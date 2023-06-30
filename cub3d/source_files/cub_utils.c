/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:29:17 by gchernys          #+#    #+#             */
/*   Updated: 2023/06/27 21:22:19 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*cub_strtrim_free(char *line, char *set)
{
	char	*str;

	str = ft_strtrim(line, set);
	if (!str)
		return (NULL);
	ft_free(&line);
	return (str);
}

void	cub_place_image(t_window **win)
{
	mlx_put_image_to_window((*win)->mlx, (*win)->window,
		(*win)->addr->i_p, 0, 0);
	mlx_destroy_image((*win)->mlx, (*win)->addr->i_p);
}

void	cub_prep_image(t_game *game, t_window **win, char flag)
{
	int	start[2];

	(*win)->addr->i_p = mlx_new_image((*win)->mlx, (*win)->window_w,
			(*win)->window_h);
	(*win)->addr->ad = mlx_get_data_addr((*win)->addr->i_p,
			&((*win)->addr->pix_bi), &((*win)->addr->line_by),
			&((*win)->addr->endian));
	if (flag == 'm')
	{
		start[0] = 0;
		start[1] = 0;
	}
	else if (flag == 'g')
	{
		start[0] = game->m_width;
		start[1] = game->m_height;
	}
	cub_draw_floor_and_ceiling(game);
	if (flag == 'm' || flag == 'g')
		cub_turn_transparent(game, (*win)->window_w, (*win)->window_h, start);
}

void	free_double_array(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i] != NULL)
		{
			if (arr[i])
				free(arr[i]);
			i++;
		}
		free(arr);
	}
}

int	return_error(char *str, t_map *map, t_game *game)
{
	if (map->map)
		free_double_array(map->map);
	if (map->north)
		free(map->north);
	if (map->south)
		free(map->south);
	if (map->west)
		free(map->west);
	if (map->east)
		free(map->east);
	if (map->floor)
		free(map->floor);
	if (map->cil)
		free(map->cil);
	free(map);
	free(game);
	ft_putstr_fd(str, 2);
	exit(1);
}
