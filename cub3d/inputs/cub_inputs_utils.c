/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_inputs_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:09:50 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/27 19:32:35 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_map_bound2(t_game *game, t_player *player, t_segment *segment)
{
	double	y;

	y = player->y_m_grid / game->m_zoom - game->m_yset;
	if (y < 0)
	{
		game->player->y_m_grid = (14 + game->m_yset) * game->m_zoom;
		if (segment->north)
		{
			segment->player_found = 0;
			segment->north->player_found = 1;
			game->start = segment->north->id;
		}
	}
	else if (y > 14)
	{
		game->player->y_m_grid = (player->y_pos / game->grid_size)
			- (13.9 * (game->y_shift + 1)) + game->m_yset
			* game->m_zoom;
		if (segment->south)
		{
			segment->player_found = 0;
			segment->south->player_found = 1;
			game->start = segment->south->id;
		}
	}
}

void	cub_map_bound(t_game *game, t_player *player, t_segment *segment,
			double x)
{
	if (x < 0)
	{
		game->player->x_m_grid = (34 + game->m_xset) * game->m_zoom;
		if (segment->west)
		{
			segment->player_found = 0;
			segment->west->player_found = 1;
			game->start = segment->west->id;
		}
	}
	else if (x > 34)
	{
		game->player->x_m_grid = (player->x_pos / game->grid_size)
			- (33.9 * (game->x_shift + 1)) + game->m_xset
			* game->m_zoom;
		if (segment->east)
		{
			segment->player_found = 0;
			segment->east->player_found = 1;
			game->start = segment->east->id;
		}
	}
	else
		cub_map_bound2(game, player, segment);
}

void	cub_undo_cont2(t_game *game, t_player *pl)
{
	if (game->keys->a == true)
	{
		game->player->y_pos += sin((pl->p_angle + 90) * (M_PI / 180))
			* pl->speed;
		game->player->x_pos -= cos((pl->p_angle + 90) * (M_PI / 180))
			* pl->speed;
		game->player->y_m_grid += sin((pl->p_angle + 90) * (M_PI / 180))
			* pl->speed / 4.0;
		game->player->x_m_grid -= cos((pl->p_angle + 90) *(M_PI / 180))
			* pl->speed / 4.0;
	}
	if (game->keys->d == true)
	{
		game->player->y_pos += sin((pl->p_angle - 90) * (M_PI / 180))
			* pl->speed;
		game->player->x_pos -= cos((pl->p_angle - 90) * (M_PI / 180))
			* pl->speed;
		game->player->y_m_grid += sin((pl->p_angle - 90) * (M_PI / 180))
			* pl->speed / 4.0;
		game->player->x_m_grid -= cos((pl->p_angle - 90) * (M_PI / 180))
			* pl->speed / 4.0;
	}
}

void	cub_undo_cont(t_game *game, t_player *pl)
{
	if (game->keys->w == true && (pl->fl_coll < 5 || pl->fr_coll < 5
			|| pl->fl2_coll < 5 || pl->fr2_coll < 5))
	{
		game->player->y_pos += sin(pl->p_angle * (M_PI / 180))
			* pl->speed;
		game->player->x_pos -= cos(pl->p_angle * (M_PI / 180))
			* pl->speed;
		game->player->y_m_grid += sin(pl->p_angle * (M_PI / 180))
			* pl->speed / 4.0;
		game->player->x_m_grid -= cos(pl->p_angle * (M_PI / 180))
			* pl->speed / 4.0;
	}
	if (game->keys->s == true)
	{
		game->player->y_pos -= sin(pl->p_angle * (M_PI / 180))
			* pl->speed;
		game->player->x_pos += cos(pl->p_angle * (M_PI / 180))
			* pl->speed;
		game->player->y_m_grid -= sin(pl->p_angle * (M_PI / 180))
			* pl->speed / 4.0;
		game->player->x_m_grid += cos(pl->p_angle * (M_PI / 180))
			* pl->speed / 4.0;
	}
}

void	cub_undo(t_game *game, t_map *map, t_player *player)
{
	int	i;

	i = -1;
	if (map->full_grid[(int)player->y_pos / 64][(int)player->x_pos / 64] == '1'
		|| cub_no_clip(map, player, map->full_grid))
	{
		cub_undo_cont(game, player);
		cub_undo_cont2(game, player);
		while (++i < game->no_of_segments)
		{
			if (map->segment[i]->player_found)
				game->start = i;
		}
	}
}
