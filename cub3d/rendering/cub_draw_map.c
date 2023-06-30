/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:03:57 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/27 19:00:53 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cub_print_m_info(t_game *game)
{
	int		spotx;
	int		spoty;
	char	*segment;

	spotx = 250;
	spoty = 280;
	mlx_string_put(game->win->mlx, game->win->window, spotx,
		spoty, 0x00000000, "MAP SECTION: ");
	segment = ft_itoa(game->start + 1);
	mlx_string_put(game->win->mlx, game->win->window, (spotx + 90),
		spoty, 0x00000000, segment);
	ft_free(&segment);
	segment = ft_itoa(game->no_of_segments);
	mlx_string_put(game->win->mlx, game->win->window, (spotx + 100),
		spoty, 0x00000000, "/");
	mlx_string_put(game->win->mlx, game->win->window, (spotx + 110),
		spoty, 0x00000000, segment);
	ft_free(&segment);
}

void	cub_draw_grid_extra(t_game *game, char **grid, int x, int y)
{
	if (grid[y][x] != 'x')
	{
		if (grid[y][x] == '0')
			game->color = 0x000000;
		if (grid[y][x] == '1')
		{
			game->color = 0x0000FF;
			cub_bressenham_mini(x + game->m_xset, y + game->m_yset, game, "xf");
		}
		cub_bressenham_mini(x + game->m_xset, y + game->m_yset, game, "xg");
		cub_bressenham_mini(x + game->m_xset, y + game->m_yset, game, "yg");
	}
	if (x != 0 && grid[y][x] == 'x' && grid[y][x - 1] != 'x')
		cub_bressenham_mini(x + game->m_xset, y + game->m_yset, game, "yg");
	if (grid[y + 1] && grid[y][x] == '1' && grid[y + 1][x] == 'x')
		cub_bressenham_mini(x + game->m_xset, y + game->m_yset + 1, game, "xg");
	if (grid[y][x] == '1' && !grid[y + 1])
		cub_bressenham_mini(x + game->m_xset, y + game->m_yset + 1, game, "xg");
}

int	cub_end_of_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == 'x')
		i++;
	if (line[i] == '\0')
		return (1);
	else
		return (0);
}

void	cub_draw_grid(t_game *game, char **grid)
{
	int	x;
	int	y;

	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x] == 'x')
			x++;
		while (grid[y][x])
		{
			if (grid[y][x] == 'x' && cub_end_of_line(grid[y] + x))
				break ;
			cub_draw_grid_extra(game, grid, x, y);
			x++;
		}
		if ((grid[y][x] == 'x' && grid[y][x - 1] == '1')
			|| (!grid[y][x] && (grid[y][x - 1] == '1' || grid[y][x -1] == '0')))
			cub_bressenham_mini(x + game->m_xset, y + game->m_yset, game, "yg");
		y++;
	}
}

void	cub_draw_m_background(t_game *game, t_window *win)
{
	win->addr->i_p = mlx_xpm_file_to_image(game->win->mlx,
			"textures/clouds.xpm", &(game->m_width), &(game->m_height));
	if (!win->addr->i_p)
	{
		write(2, "Texture file couldn't open or corrupted\n", 40);
		cub_close_x(game);
	}
	win->addr->ad = mlx_get_data_addr(win->addr->i_p, &(win->addr->pix_bi),
			&(win->addr->line_by), &win->addr->endian);
	mlx_put_image_to_window(game->win->mlx, game->win->window,
		game->win->addr->i_p, 0, 0);
	mlx_destroy_image(game->win->mlx, game->win->addr->i_p);
}
