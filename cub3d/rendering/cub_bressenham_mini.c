/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bressenham_mini.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:10:23 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/24 11:33:01 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_game *game, int x, int y)
{
	char	*dst;

	if ((x >= 0 && y >= 0) && (x < game->win->window_w
			&& y < game->win->window_h))
	{
		dst = game->win->addr->ad + (y * game->win->addr->line_by + x
				* (game->win->addr->pix_bi / 8));
		*(unsigned int *)dst = game->color;
	}
}

void	cub_bressenham_mini_decision(t_game *game, t_bress *bress, int i)
{
	while (i < bress->x_step)
	{
		my_mlx_pixel_put(game, bress->x, bress->y);
		if (bress->swap)
			bress->y += bress->signy;
		else
			bress->x += bress->signx;
		i++;
	}
}

void	cub_fill_grid(t_game *game, t_bress *bress, int i)
{
	int	j;
	int	start;

	j = -1;
	bress->x += 1;
	start = bress->x;
	while (++j < 16)
	{
		i = 0;
		bress->x = start;
		while (i <= bress->x_step)
		{			
			my_mlx_pixel_put(game, bress->x, bress->y);
			bress->x += 1;
			i++;
		}
		bress->y += 1;
	}
}

void	cub_bressenham_mini_frag(t_game *game, t_bress *bress, char *flag)
{
	int	i;

	bress->x_step = fabs(bress->deltax[1] - bress->deltax[0]);
	bress->y_step = fabs(bress->deltay[1] - bress->deltay[0]);
	bress->swap = 0;
	bress->x = bress->deltax[0];
	bress->y = bress->deltay[0];
	bress->p = (2 * bress->y_step) - bress->x_step;
	i = 0;
	if (bress->y_step >= bress->x_step)
	{
		bress->temp = bress->x_step;
		bress->x_step = bress->y_step;
		bress->y_step = bress->temp;
		bress->swap = 1;
	}
	if (flag[1] == 'f')
		cub_fill_grid(game, bress, i);
	else
		cub_bressenham_mini_decision(game, bress, i);
	ft_free(&bress);
}

void	cub_bressenham_mini(int x, int y, t_game *game, char *flag)
{
	t_bress	*bress;

	bress = calloc(1, sizeof(t_bress));
	if (flag[0] == 'x')
	{
		bress->deltax[0] = x * (game->m_zoom);
		bress->deltay[0] = y * (game->m_zoom);
		bress->deltax[1] = (x + 1) * (game->m_zoom);
		bress->deltay[1] = y * (game->m_zoom);
	}
	if (flag[0] == 'y')
	{
		bress->deltax[0] = x * (game->m_zoom);
		bress->deltay[0] = y * (game->m_zoom);
		bress->deltax[1] = x * (game->m_zoom);
		bress->deltay[1] = (y + 1) * (game->m_zoom);
	}
	bress->signx = 1;
	bress->signy = 1;
	if (bress->deltax[1] - bress->deltax[0] < 0)
		bress->signx = -1;
	if (bress->deltay[1] - bress->deltay[0] < 0)
		bress->signy = -1;
	cub_bressenham_mini_frag(game, bress, flag);
}
