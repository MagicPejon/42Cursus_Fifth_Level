/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_find_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:42:56 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/27 19:14:01 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	cub_scan_player(t_game *game, char *line, int k)
{
	int		i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W')
		{
			game->player->x_m_grid = (ft_find_char(line, line[i])
					+ game->m_xset) * game->m_zoom + (game->m_zoom / 2);
			game->player->y_m_grid = (k + game->m_yset)
				* game->m_zoom + (game->m_zoom / 2);
			return (1);
		}
	}
	return (0);
}

int	cub_find_player(t_game *game, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->full_grid[++i] && !game->player->dir)
	{
		j = -1;
		while (map->full_grid[i][++j])
		{
			if (map->full_grid[i][j] == 'N' || map->full_grid[i][j] == 'S'
				|| map->full_grid[i][j] == 'E' || map->full_grid[i][j] == 'W')
			{
				game->player->x = j;
				game->player->y = i;
				game->player->dir = map->full_grid[i][j];
				break ;
			}
		}
	}
	return (1);
}
