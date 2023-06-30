/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_segments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:46:40 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/27 19:26:10 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	connect_segments_p2(t_game *game, int i, int h, int v)
{
	i = game->m_horizontal * v;
	h = 1;
	while (h < game->m_horizontal)
	{
		game->map->segment[i]->east = game->map->segment[i + 1];
		game->map->segment[i + 1]->west = game->map->segment[i];
		i++;
		h++;
	}
	i = game->m_horizontal * v;
	h = 0;
	if (v != game->m_vertical - 1)
	{
		while (h < game->m_horizontal)
		{
			game->map->segment[i]->south
				= game->map->segment[i + game->m_horizontal];
			game->map->segment[i + game->m_horizontal]->north
				= game->map->segment[i];
			i++;
			h++;
		}
	}
}

void	connect_segments(t_game *game)
{
	int	i;
	int	h;
	int	v;

	i = 0;
	h = 1;
	v = 0;
	if (game->no_of_segments != 1)
	{
		while (v < game->m_vertical)
		{
			connect_segments_p2(game, i, h, v);
			v++;
		}
	}
}

char	**load_grid(t_game *game, int i, int x, int y)
{
	int		j;
	int		k;
	char	**grid;

	j = y;
	k = 0;
	grid = ft_calloc(14 + 1, sizeof(char *));
	if (!grid)
		return (NULL);
	while (game->map->full_grid[j] && (k < 14))
	{
		grid[k] = ft_substr(game->map->full_grid[j], x, 34);
		if (!grid[k])
			return (NULL);
		if (cub_scan_player(game, grid[k], k))
		{
			game->map->segment[i]->player_found = 1;
			game->start = i;
		}
		j++;
		k++;
	}
	grid[k] = NULL;
	return (grid);
}

void	segment_init(t_game *game)
{
	int	i;

	i = -1;
	game->map->segment
		= ft_calloc(game->no_of_segments + 1, sizeof(t_segment));
	if (!game->map->segment)
		cub_return_error("Error\n Malloc error\n\n", game->map, game);
	while (++i < game->no_of_segments)
	{
		game->map->segment[i] = ft_calloc(1, sizeof(t_segment));
		if (!game->map->segment[i])
			cub_return_error("Error\n Malloc error\n\n", game->map, game);
		game->map->segment[i]->player_found = 0;
		game->map->segment[i]->next = NULL;
		game->map->segment[i]->north = NULL;
		game->map->segment[i]->south = NULL;
		game->map->segment[i]->east = NULL;
		game->map->segment[i]->west = NULL;
	}
}

void	fill_segments(t_game *game)
{
	int	i;
	int	coord[2];

	segment_init(game);
	i = -1;
	coord[0] = 0;
	coord[1] = 0;
	while (++i < game->no_of_segments)
	{
		game->map->segment[i]->id = i;
		if (i != 0)
			game->map->segment[i - 1]->next = game->map->segment[i];
		else if (i == game->no_of_segments - 1)
			game->map->segment[i]->next = game->map->segment[0];
		game->map->segment[i]->grid = load_grid(game, i, coord[0], coord[1]);
		if (!game->map->segment[i]->grid)
			cub_return_error("Error\n Malloc error\n\n", game->map, game);
		coord[0] += 34;
		if (ft_strlen(game->map->segment[i]->grid[0]) < 34)
		{
			coord[0] = 0;
			coord[1] += 14;
		}
	}
	connect_segments(game);
}
