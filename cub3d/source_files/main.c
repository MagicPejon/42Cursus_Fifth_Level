/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:12:32 by gchernys          #+#    #+#             */
/*   Updated: 2023/06/28 18:03:02 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	cub_mlx_keys(t_game *game)
{
	game->keys = ft_calloc(1, sizeof(t_keys));
	mlx_hook(game->win->window, 17, 0, cub_close_x, game);
	mlx_hook(game->win->window, 2, 0, cub_key_press, game);
	mlx_hook(game->win->window, 3, 0, cub_key_release, game);
	mlx_loop_hook(game->win->mlx, cub_inputs, game);
	mlx_loop(game->win->mlx);
}

void	cub_get_textures(t_game *game, t_texture **tex, int i, char *dir)
{
	game->tex[i]->i_p = mlx_xpm_file_to_image(game->win->mlx, dir,
			&(game->tex[i]->t_width), &(game->tex[i]->t_height));
	if (!game->tex[i]->i_p)
		cub_return_error("Error\n Texture file couldn't open or corrupted\n",
			game->map, game);
	game->tex[i]->ad = (int *)mlx_get_data_addr(tex[i]->i_p, &(tex[i]->pix_bi),
			&(tex[i]->line_by), &(tex[i]->endian));
	if (!game->tex[i]->i_p)
		cub_return_error("Error\n Texture file couldn't open or corrupted\n",
			game->map, game);
	game->tex[i]->repeat = 0;
	game->tex[i]->skip = 0;
}

void	cub_set_textures(t_game *game, t_map *map)
{
	int	i;

	i = -1;
	game->tex = ft_calloc(4, sizeof(t_texture));
	if (!game->tex)
		cub_return_error("Error\n Malloc failed\n", map, game);
	while (++i < 4)
	{
		game->tex[i] = ft_calloc(1, sizeof(t_texture));
		if (!game->tex[i])
			cub_return_error("Error\n Malloc failed\n", map, game);
		if (i == 0)
			cub_get_textures(game, game->tex, i, map->north);
		else if (i == 1)
			cub_get_textures(game, game->tex, i, map->south);
		else if (i == 2)
			cub_get_textures(game, game->tex, i, map->east);
		else if (i == 3)
			cub_get_textures(game, game->tex, 3, map->west);
	}
}

static void	cub_map_init(t_map *map)
{
	map->map = NULL;
	map->full_grid = NULL;
	map->floor = NULL;
	map->cil = NULL;
	map->north = NULL;
	map->south = NULL;
	map->east = NULL;
	map->west = NULL;
}

int	main(int argc, char **argv)
{
	t_game	*game;

	basic_error_check(argc, argv);
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
	{
		write(2, "Error\n Malloc error\n", 21);
		return (1);
	}
	game->grid_size = 64;
	game->map = (t_map *)malloc(sizeof(t_map));
	if (!game->map)
	{
		ft_free(&game);
		write(2, "Error\n Malloc error\n", 21);
		return (1);
	}
	cub_map_init(game->map);
	if (malloc_map(game->map, argv[1], game))
		return_error("Error\n Malloc error\n\n", game->map, game);
	game->map->check = 0;
	load_map(game, game->map, argv[1], 0);
	cub_init(game);
	cub_mlx_keys(game);
	return (0);
}
