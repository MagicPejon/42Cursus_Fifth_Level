/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_back_collisions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:39:32 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/28 14:35:35 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_protect_boundaries_x(t_map *map, double *point)
{
	if (*point / 64 < 0)
		*point = 0;
	if (*point / 64 > map->wide)
		*point = map->wide;
}

void	cub_protect_boundaries_y(t_map *map, double *point)
{
	if (*point / 64 < 0)
		*point = 0;
	if (*point / 64 > map->high)
		*point = map->high;
}

double	cub_back_horizontal(t_map *map, t_player *player, char **full_grid,
			double angle)
{
	double	horiz_i[2];

	ft_bzero(horiz_i, sizeof(double) * 2);
	if (angle == 0.0 || angle == 180.0)
		return (INT_MAX);
	else if (angle > 0.0 && angle < 180.0)
	{
		horiz_i[1] = floor(player->y_pos / 64.0) * 64.0 - 0.0001;
		horiz_i[0] = player->x_pos + (player->y_pos
				- horiz_i[1]) / tan(angle * (M_PI / 180.0));
	}
	else if (angle > 180.0 && angle < 360.0)
	{
		horiz_i[1] = floor(player->y_pos / 64.0) * 64.0 + 64.0;
		horiz_i[0] = player->x_pos + (player->y_pos
				- horiz_i[1]) / tan(player->r_angle * (M_PI / 180.0));
	}
	cub_protect_boundaries_x(map, &horiz_i[0]);
	cub_protect_boundaries_y(map, &horiz_i[1]);
	if (full_grid[(int)horiz_i[1] / 64][(int)horiz_i[0] / 64] == '1')
		return (sqrt((horiz_i[0] - player->x_pos)
				* (horiz_i[0] - player->x_pos)
				+ (horiz_i[1] - player->y_pos)
				* (horiz_i[1] - player->y_pos)));
	return (INT_MAX);
}

double	cub_back_vertical(t_map *map, t_player *player, char **full_grid,
			double angle)
{
	double	verti_i[2];

	ft_bzero(verti_i, sizeof(double) * 2);
	if (angle == 90.0 || angle == 270.0)
		return (INT_MAX);
	else if (angle > 270.0 || angle < 90.0)
	{
		verti_i[0] = floor(player->x_pos / 64.0) * 64.0 + 64.0;
		verti_i[1] = player->y_pos + (player->x_pos
				- verti_i[0]) * tan(angle * (M_PI / 180.0));
	}
	else if (angle > 90.0 && angle < 270.0)
	{
		verti_i[0] = floor(player->x_pos / 64.0) * 64.0 - 0.0001;
		verti_i[1] = player->y_pos + (player->x_pos
				- verti_i[0]) * tan(angle * (M_PI / 180.0));
	}
	cub_protect_boundaries_x(map, &verti_i[0]);
	cub_protect_boundaries_y(map, &verti_i[1]);
	if (full_grid[(int)verti_i[1] / 64][(int)verti_i[0] / 64] == '1')
		return (sqrt((verti_i[0] - player->x_pos)
				* (verti_i[0] - player->x_pos)
				+ (verti_i[1] - player->y_pos)
				* (verti_i[1] - player->y_pos)));
	return (INT_MAX);
}

double	cub_back_collisions(t_game *game, t_player *player, double angle)
{
	double	verti_dis;
	double	horiz_dis;

	if (angle < 0)
		angle += 360;
	else if (angle > 360)
		angle -= 360;
	verti_dis = cub_back_vertical(game->map, player,
			game->map->full_grid, angle);
	horiz_dis = cub_back_horizontal(game->map, player,
			game->map->full_grid, angle);
	if (verti_dis < horiz_dis)
		return (verti_dis);
	else
		return (horiz_dis);
}
