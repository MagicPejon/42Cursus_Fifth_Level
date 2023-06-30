/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_ui.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:01:03 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/24 11:33:14 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_draw_outline(t_game *game, t_bress bress)
{
	bress.x -= 1;
	my_mlx_pixel_put(game, bress.x, bress.y);
	bress.y -= 1;
	my_mlx_pixel_put(game, bress.x, bress.y);
	bress.x += 1;
	my_mlx_pixel_put(game, bress.x, bress.y);
	bress.x += 1;
	my_mlx_pixel_put(game, bress.x, bress.y);
	bress.y += 1;
	my_mlx_pixel_put(game, bress.x, bress.y);
	bress.y += 1;
	my_mlx_pixel_put(game, bress.x, bress.y);
	bress.x -= 1;
	my_mlx_pixel_put(game, bress.x, bress.y);
	bress.x -= 1;
	my_mlx_pixel_put(game, bress.x, bress.y);
}

void	cub_draw_cursor(t_game *game, t_player *player)
{
	t_bress	bress;

	if (game->map->segment[game->start]->player_found)
	{
		game->color = 0x00ffd700;
		bress.x = player->x_m_grid;
		bress.y = player->y_m_grid;
		my_mlx_pixel_put(game, bress.x, bress.y);
		game->color = 0x00b59410;
		cub_draw_outline(game, bress);
	}
}

void	cub_turn_transparent(t_game *game, int width, int height, int *start)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	game->color = 0xFF000000;
	while (y <= height)
	{
		x = -1;
		if (y < start[1])
		{
			while (++x <= start[0])
				my_mlx_pixel_put(game, x, y);
			if (y == start[1] - 1)
				break ;
		}
		else
		{
			while (++x <= width)
				my_mlx_pixel_put(game, x, y);
		}
		y++;
	}
}

void	cub_draw_ui(t_game *game)
{
	cub_prep_image(game, &(game->win), 'm');
	cub_draw_grid(game, game->map->segment[game->start]->grid);
	cub_print_m_info(game);
	cub_draw_cursor(game, game->player);
	cub_place_image(&(game->win));
}
