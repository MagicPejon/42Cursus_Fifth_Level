/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_and_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 07:35:06 by gchernys          #+#    #+#             */
/*   Updated: 2023/06/27 20:40:47 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

unsigned long	setrgb(int red, int green, int blue)
{
	return (((red & 0xff) << 16) + ((green & 0xff) << 8) + (blue & 0xff));
}

int	check_rgb(char **str)
{
	int	i;
	int	j;

	j = 0;
	while (str[j])
	{
		str[j] = cub_strtrim_free(str[j], " \t\n\v\f\r");
		if (!str[j] || str[j][0] == '\0')
			return (PARSE_ERR);
		i = 0;
		while (str[j][i])
		{
			if (!ft_isdigit(str[j][i]))
				return (PARSE_ERR);
			i++;
		}
		if (ft_atoi(str[j]) > 255 || ft_atoi(str[j]) < 0)
			return (PARSE_ERR);
		j++;
	}
	if (j != 3)
		return (PARSE_ERR);
	return (0);
}

int	set_textures(t_map *map)
{
	int	j;
	int	i;
	int	k;

	j = -1;
	while (j++ < 6)
	{
		i = 0;
		k = i + 2;
		map->map[j] = cub_strtrim_free(map->map[j], " \t\n\v\f\r");
		if (ft_strncmp(map->map[j] + i, "NO ", 3) == 0)
			map->north = ft_substr(map->map[j], k + spacecount(map->map[j], k), \
			ft_strlen(map->map[j]) - k - spacecount(map->map[j], k));
		else if (ft_strncmp(map->map[j] + i, "SO ", 3) == 0)
			map->south = ft_substr(map->map[j], k + spacecount(map->map[j], k), \
			ft_strlen(map->map[j]) - k - spacecount(map->map[j], k));
		else if (ft_strncmp(map->map[j] + i, "WE ", 3) == 0)
			map->west = ft_substr(map->map[j], k + spacecount(map->map[j], k), \
			ft_strlen(map->map[j]) - k - spacecount(map->map[j], k));
		else if (ft_strncmp(map->map[j] + i, "EA ", 3) == 0)
			map->east = ft_substr(map->map[j], k + spacecount(map->map[j], k), \
			ft_strlen(map->map[j]) - k - spacecount(map->map[j], k));
	}
	return (0);
}

int	find_rgb(t_map *map)
{
	int	j;
	int	i;
	int	k;

	j = -1;
	while (j++ < 6)
	{
		i = 0;
		while (ft_space(map->map[j][i]))
			i++;
		k = i + 2;
		if (ft_strncmp(map->map[j] + i, "F ", 2) == 0)
			map->floor = ft_substr(map->map[j], k + spacecount(map->map[j], k), \
			ft_strlen(map->map[j]) - k - spacecount(map->map[j], k));
		else if (ft_strncmp(map->map[j] + i, "C ", 2) == 0)
			map->cil = ft_substr(map->map[j], k + spacecount(map->map[j], k), \
			ft_strlen(map->map[j]) - k - spacecount(map->map[j], k));
	}
	if (map->floor == NULL || map->cil == NULL || init_rgb(map) == PARSE_ERR)
		return (PARSE_ERR);
	return (0);
}

int	init_rgb(t_map *map)
{
	char			**temp;

	temp = ft_split(map->floor, ',');
	if (check_rgb(temp) == PARSE_ERR || cub_comma_count(map->floor) > 2)
	{
		free_double_array(temp);
		return (PARSE_ERR);
	}
	map->floor_color = setrgb(ft_atoi(temp[0]), ft_atoi(temp[1]), \
	ft_atoi(temp[2]));
	free_double_array(temp);
	temp = ft_split(map->cil, ',');
	if (check_rgb(temp) == PARSE_ERR || cub_comma_count(map->cil) > 2)
	{
		free_double_array(temp);
		return (PARSE_ERR);
	}
	map->ceiling_color = setrgb(ft_atoi(temp[0]), ft_atoi(temp[1]), \
	ft_atoi(temp[2]));
	free_double_array(temp);
	return (0);
}
