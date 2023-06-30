/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:53:43 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/28 14:56:32 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_free_textures(t_game *game)
{
	int	i;

	i = -1;
	if (game->tex)
	{
		while (++i < 4)
		{
			if (game->tex[i])
			{
				if (game->tex[i]->i_p)
					mlx_destroy_image(game->win->mlx, game->tex[i]->i_p);
			}
			ft_free(&game->tex[i]);
		}
		ft_free(&game->tex);
	}
}

void	cub_free_segments(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	if (game->map)
	{
		if (game->map->segment)
		{
			while (game->map->segment[++i])
			{
				j = -1;
				while (game->map->segment[i]->grid[++j])
					ft_free(&game->map->segment[i]->grid[j]);
				ft_free(&game->map->segment[i]->grid);
				ft_free(&game->map->segment[i]);
			}
			ft_free(&game->map->segment);
		}
	}
}

static	void	cub_free_data(t_map *map)
{
	ft_free(&map->floor);
	ft_free(&map->cil);
	ft_free(&map->north);
	ft_free(&map->south);
	ft_free(&map->east);
	ft_free(&map->west);
}

void	cub_free_map(t_game *game)
{
	int	i;

	i = -1;
	if (game->map)
	{
		if (game->map->map)
		{
			while (++i < game->map->full_high)
			{
				ft_free(&game->map->map[i]);
				if (game->map->full_grid)
				{
					if (i < game->map->high)
						ft_free(&game->map->full_grid[i]);
				}
			}
			ft_free(&game->map->map);
			ft_free(&game->map->full_grid);
		}
		cub_free_data(game->map);
	}
}
