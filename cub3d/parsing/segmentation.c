/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segmentation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:19:41 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/28 14:32:54 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	fill_corners_end(t_game *game, int i, int j, int k)
{
	if (game->map->map[j][k] == 'x' && game->map->map[j][k + 1] == '1'
		&& game->map->map[j - 1][k] == '1')
		game->map->full_grid[i][k] = '1';
	while (game->map->full_grid[i][++k])
	{
		if (game->map->map[j][k] == 'x' && game->map->map[j][k - 1] == '1'
		&& game->map->map[j - 1][k] == '1')
			game->map->full_grid[i][k] = '1';
	}
}

void	fill_corners_middle(t_game *game, int i, int j, int k)
{
	if (game->map->map[j][k] == 'x' && game->map->map[j][k + 1] == '1'
		&& (game->map->map[j + 1][k] == '1'
		|| game->map->map[j - 1][k] == '1'))
		game->map->full_grid[i][k] = '1';
	while (game->map->full_grid[i][++k])
	{
		if (game->map->map[j][k] == 'x' && (game->map->map[j][k + 1] == '1'
			|| game->map->map[j][k - 1] == '1')
			&& (game->map->map[j + 1][k] == '1'
			|| game->map->map[j - 1][k] == '1'))
			game->map->full_grid[i][k] = '1';
	}
}

void	fill_corners(t_game *game, int i, int j)
{
	int	k;

	k = 0;
	if (i == 0)
	{
		if (game->map->map[j][k] == 'x' && game->map->map[j][k + 1] == '1'
			&& game->map->map[j + 1][k] == '1')
			game->map->full_grid[i][k] = '1';
		while (game->map->full_grid[i][++k])
		{
			if (game->map->map[j][k] == 'x' && game->map->map[j][k - 1] == '1'
			&& game->map->map[j + 1][k] == '1')
				game->map->full_grid[i][k] = '1';
		}
	}
	else if (i < game->map->high - 7)
		fill_corners_middle(game, i, j, k);
	else
		fill_corners_end(game, i, j, k);
}

void	load_grid_segments(t_game *game, char *temp, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 6;
	ft_free(&temp);
	ft_free(&str);
	game->player = ft_calloc(1, sizeof(t_player));
	if (!game->player)
		return_error("Error\n Malloc error\n\n", game->map, game);
	game->map->full_grid
		= ft_calloc((game->map->high - 6 + 1), sizeof(char *));
	if (!game->map->full_grid)
		cub_return_error("Error\n Malloc error\n\n", game->map, game);
	while (game->map->map[j])
	{
		game->map->full_grid[i] = ft_strdup(game->map->map[j]);
		if (!game->map->full_grid[i])
			cub_return_error("Error\n Malloc error\n\n", game->map, game);
		fill_corners(game, i, j);
		i++;
		j++;
	}
	game->map->high = i;
}
