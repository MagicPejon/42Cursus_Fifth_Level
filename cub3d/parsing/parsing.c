/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:12:34 by gchernys          #+#    #+#             */
/*   Updated: 2023/06/27 21:34:44 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	basic_error_check(int argc, char **argv)
{
	char	*str;
	int		i;

	if (argc != 2)
	{
		write(2, "Error\n Invalid number of arguments", 34);
		exit(PARSE_ERR);
	}
	str = argv[1];
	i = ft_strlen(argv[1]);
	if (str[i - 1] != 'b' || str[i - 2] != 'u' || \
	str[i - 3] != 'c' || str[i - 4] != '.')
	{
		write(2, "Error\n File needs to end with \".cub\" extension\n", 47);
		exit(PARSE_ERR);
	}
	i = open(argv[1], O_RDONLY);
	if (i < 0)
	{
		write(2, "Error\n Couldn't open file", 25);
		exit(PARSE_ERR);
	}
	close (i);
	return (0);
}

static int	cub_check_file_extensions(t_map *map)
{
	int	i;

	i = ft_lastoccur(map->north, '.');
	if (i == 0)
		return (1);
	if (map->north[i + 1] != 'x' || map->north[i + 2] != 'p' || \
	map->north[i + 3] != 'm' || map->north[i + 4] != '\0')
		return (1);
	i = ft_lastoccur(map->south, '.');
	if (map->south[i + 1] != 'x' || map->south[i + 2] != 'p' || \
	map->south[i + 3] != 'm' || map->south[i + 4] != '\0')
		return (1);
	i = ft_lastoccur(map->east, '.');
	if (map->east[i + 1] != 'x' || map->east[i + 2] != 'p' || \
	map->east[i + 3] != 'm' || map->east[i + 4] != '\0')
		return (1);
	i = ft_lastoccur(map->west, '.');
	if (map->west[i + 1] != 'x' || map->west[i + 2] != 'p' || \
	map->west[i + 3] != 'm' || map->west[i + 4] != '\0')
		return (1);
	return (0);
}

int	check_textures(t_map *map)
{
	set_textures(map);
	if (map->north == NULL || map->south == NULL || map->west == NULL || \
	map->east == NULL)
		return (PARSE_ERR);
	if (cub_check_file_extensions(map))
		return (PARSE_ERR);
	if (map->north[0] == '\0' || map->south[0] == '\0' || \
		map->west[0] == '\0' || map->east[0] == '\0')
		return (PARSE_ERR);
	return (0);
}

void	cub_draw_floor_and_ceiling(t_game *game)
{
	unsigned int	i;
	unsigned int	*dst;

	i = game->win->window_w * game->win->window_h / 2;
	dst = (unsigned int *) game->win->addr->ad;
	while (--i > 0)
		*dst++ = game->map->ceiling_color;
	i = game->win->window_w * game->win->window_h / 2;
	while (--i > 0)
		*dst++ = game->map->floor_color;
}
