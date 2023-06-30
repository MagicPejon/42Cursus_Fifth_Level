/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_calc_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:08:51 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/27 19:33:06 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_get_distance(t_game *game, t_player *player, char *r_flag,
						char flag)
{
	if (*r_flag == 0)
		*r_flag = 'p';
	else if (*r_flag == 'p')
		*r_flag = 'r';
	if (flag == 'v')
	{
		cub_grid_mult_verti(game, player);
		game->player->verti_dis = sqrt((player->verti_i[0] - player->x_pos)
				* (player->verti_i[0] - game->player->x_pos)
				+ (player->verti_i[1] - game->player->y_pos)
				* (player->verti_i[1] - game->player->y_pos));
		cub_grid_div_verti(game, player);
	}
	else if (flag == 'h')
	{
		cub_grid_mult_hori(game, player);
		game->player->horiz_dis = sqrt((player->horiz_i[0] - player->x_pos)
				* (player->horiz_i[0] - game->player->x_pos)
				+ (player->horiz_i[1] - game->player->y_pos)
				* (player->horiz_i[1] - game->player->y_pos));
		cub_grid_div_hori(game, player);
	}
}

int	cub_subsequent_intersect(t_game *game, t_map *m, t_player *play)
{
	char	r_flag;

	r_flag = 0;
	game->player->prot_flag = cub_find_intersect(game, m, play, 's');
	if (game->player->prot_flag != 'v')
	{
		if (m->full_grid[(int)play->verti_i[1]][(int)play->verti_i[0]]
			== '1')
			cub_get_distance(game, play, &r_flag, 'v');
	}
	if (game->player->prot_flag != 'h')
	{
		if (m->full_grid[(int)play->horiz_i[1]][(int)play->horiz_i[0]]
			== '1')
			cub_get_distance(game, play, &r_flag, 'h');
	}
	if (r_flag == 'r' || (r_flag == 'p'
			&& (play->prot_flag == 'v' || play->prot_flag == 'h')))
		return (1);
	return (0);
}

/**
 * @brief 
 * 
 * @param game 
 * @param map 
 * @param player 
 * @return int 
 * 
 * @note grid[1] is y, grid[0] is x
 */
int	cub_first_intersect(t_game *game, t_map *m, t_player *play)
{
	char	r_flag;

	r_flag = 0;
	game->player->prot_flag = cub_find_intersect(game, m, play, 'f');
	if (play->prot_flag != 'v')
	{
		if (m->full_grid[(int)play->verti_i[1]][(int)play->verti_i[0]]
			== '1')
			cub_get_distance(game, play, &r_flag, 'v');
	}
	if (play->prot_flag != 'h')
	{
		if (m->full_grid[(int)play->horiz_i[1]][(int)play->horiz_i[0]]
			== '1')
			cub_get_distance(game, play, &r_flag, 'h');
	}
	if (r_flag == 'r')
		return (1);
	return (0);
}

void	cub_calc_player(t_game *game, t_player *player, t_window *win)
{
	cub_prep_image(game, &(game->win), 'n');
	while (player->rays <= player->fov)
	{
		if (cub_first_intersect(game, game->map, game->player))
			cub_draw_column(game, player, win);
		else
		{
			while (1)
			{
				if (cub_subsequent_intersect(game, game->map,
						game->player))
					break ;
			}
			cub_draw_column(game, player, win);
		}
		game->player->r_angle -= (double)player->fov / (double)win->window_w;
		if (player->r_angle < 0)
			game->player->r_angle = player->r_angle + 360;
		game->player->rays += (double)player->fov / (double)win->window_w;
		game->player->verti_dis = INT_MAX;
		game->player->horiz_dis = INT_MAX;
	}
	cub_place_image(&(game->win));
}
