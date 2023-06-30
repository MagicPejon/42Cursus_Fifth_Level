/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_press_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 13:19:50 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/27 19:49:08 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_esc(t_game *game)
{
	mlx_destroy_window(game->win->mlx, game->win->window);
	cub_free_textures(game);
	cub_free_map(game);
	cub_free_segments(game);
	ft_free(&(game->map));
	ft_free(&(game->keys));
	ft_free(&(game->win->addr));
	ft_free(&(game->win));
	ft_free(&(game->player->verti_i));
	ft_free(&(game->player->horiz_i));
	ft_free(&(game)->player);
	ft_free(&(game));
	exit(0);
}

void	cub_change_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->keys->m_switch)
	{
		if (game->start < game->no_of_segments - 1)
				game->start++;
		else
				game->start = 0;
	}
	if (game->keys->m_player)
	{
		while (!game->map->segment[i]->player_found)
			i++;
		game->start = i;
	}
}

void	cub_movement(int key, t_game *game)
{
	if (key == 13)
		game->keys->w = true;
	if (key == 1)
		game->keys->s = true;
	if (key == 0)
		game->keys->a = true;
	if (key == 2)
		game->keys->d = true;
	if (key == 123)
		game->keys->l_arrow = true;
	if (key == 124)
		game->keys->r_arrow = true;
	if (key == 6)
	{
		if (game->keys->shift == false)
			game->keys->shift = true;
		else if (game->keys->shift == true)
			game->keys->shift = false;
	}
}

int	cub_key_press(int key, t_game *game)
{
	cub_movement(key, game);
	if (key == 18 || key == 19 || key == 20)
	{
		if (key == 18)
			game->keys->m_switch = true;
		if (key == 19)
			game->keys->m_player = true;
		if (key == 20)
			game->keys->m_reset = true;
		cub_change_map(game);
	}
	if (key == 53)
		cub_esc(game);
	return (0);
}

int	cub_key_release(int key, t_game *game)
{
	if (key == 13)
		game->keys->w = false;
	if (key == 1)
		game->keys->s = false;
	if (key == 0)
		game->keys->a = false;
	if (key == 2)
		game->keys->d = false;
	if (key == 123)
		game->keys->l_arrow = false;
	if (key == 124)
		game->keys->r_arrow = false;
	if (key == 18)
		game->keys->m_switch = false;
	if (key == 19)
		game->keys->m_player = false;
	if (key == 20)
		game->keys->m_reset = false;
	return (0);
}
