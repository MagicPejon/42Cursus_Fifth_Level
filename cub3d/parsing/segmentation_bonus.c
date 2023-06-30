/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segmentation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:19:41 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/28 14:33:18 by amalbrei         ###   ########.fr       */
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

static int	count_segments(t_game *game, char **full_grid, int i)
{
	int	total;

	game->m_zoom = game->grid_size / 4;
	game->m_xset = 2;
	game->m_yset = 2;
	game->map->wide = ft_strlen(game->map->full_grid[0]);
	game->map->high = i;
	game->m_horizontal = ft_strlen(full_grid[0]);
	game->m_horizontal = (game->m_horizontal / 34) + 1;
	game->m_vertical = 0;
	while (full_grid[game->m_vertical])
		game->m_vertical++;
	game->m_vertical = (game->m_vertical / 14) + 1;
	total = game->m_horizontal * game->m_vertical;
	return (total);
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
	game->no_of_segments = count_segments(game, game->map->full_grid, i);
	fill_segments(game);
}
