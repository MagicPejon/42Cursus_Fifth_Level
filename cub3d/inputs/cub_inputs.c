/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_inputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:24:15 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/27 19:05:28 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_change_speed(t_game *game)
{
	if (game->keys->shift == true)
		game->player->speed = 4;
	else if (game->keys->shift == false)
		game->player->speed = 2;
}

void	cub_turn_player(t_game *game)
{
	if (game->keys->l_arrow == true)
		game->player->p_angle += game->player->speed;
	if (game->keys->r_arrow == true)
		game->player->p_angle -= game->player->speed;
	if (game->player->p_angle > 359.0)
		game->player->p_angle = game->player->p_angle - 360;
	if (game->player->p_angle < 0.0)
		game->player->p_angle = game->player->p_angle + 360;
}

void	cub_strafe_player(t_game *game, t_player *player)
{
	if (game->keys->a == true)
	{
		game->player->y_pos -= sin((player->p_angle + 90) * (M_PI / 180))
			* player->speed;
		game->player->x_pos += cos((player->p_angle + 90) * (M_PI / 180))
			* player->speed;
		game->player->y_m_grid -= sin((player->p_angle + 90) * (M_PI / 180))
			* player->speed / 4.0;
		game->player->x_m_grid += cos((player->p_angle + 90) * (M_PI / 180))
			* player->speed / 4.0;
	}
	if (game->keys->d == true)
	{
		game->player->y_pos -= sin((player->p_angle - 90) * (M_PI / 180))
			* game->player->speed;
		game->player->x_pos += cos((player->p_angle - 90) * (M_PI / 180))
			* game->player->speed;
		game->player->y_m_grid -= sin((player->p_angle - 90) * (M_PI / 180))
			* player->speed / 4.0;
		game->player->x_m_grid += cos((player->p_angle - 90) * (M_PI / 180))
			* player->speed / 4.0;
	}
}

void	cub_move_player(t_game *game, t_player *player)
{
	if (game->keys->w == true)
	{
		game->player->y_pos -= sin(player->p_angle * (M_PI / 180))
			* player->speed;
		game->player->x_pos += cos(player->p_angle * (M_PI / 180))
			* player->speed;
		game->player->y_m_grid -= sin(player->p_angle * (M_PI / 180))
			* player->speed / 4.0;
		game->player->x_m_grid += cos(player->p_angle * (M_PI / 180))
			* player->speed / 4.0;
	}
	if (game->keys->s == true)
	{
		game->player->y_pos += sin(player->p_angle * (M_PI / 180))
			* game->player->speed;
		game->player->x_pos -= cos(player->p_angle * (M_PI / 180))
			* game->player->speed;
		game->player->y_m_grid += sin(player->p_angle * (M_PI / 180))
			* player->speed / 4.0;
		game->player->x_m_grid -= cos(player->p_angle * (M_PI / 180))
			* player->speed / 4.0;
	}
}

int	cub_inputs(t_game *game)
{
	int	i;

	i = -1;
	cub_move_player(game, game->player);
	cub_strafe_player(game, game->player);
	cub_undo(game, game->map, game->player);
	cub_turn_player(game);
	cub_change_speed(game);
	while (++i < game->no_of_segments)
	{
		if (game->map->segment[i]->player_found)
			cub_map_bound(game, game->player, game->map->segment[i],
				game->player->x_m_grid / game->m_zoom - game->m_xset);
	}
	if (game->keys->m_reset)
		cub_reset_map(game);
	cub_draw(game);
	return (0);
}
