/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:03:26 by gchernys          #+#    #+#             */
/*   Updated: 2023/06/28 10:56:58 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	validate_player_count(char **tempmap)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	j = 6;
	while (tempmap[j])
	{
		i = 0;
		while (tempmap[j][i])
		{
			if (ft_strchr("NSWE", tempmap[j][i]))
				count++;
			i++;
			if (!ft_strchr("10NSEW \tx", tempmap[j][i]))
				return (PARSE_ERR);
		}
		j++;
	}
	if (count != 1)
		return (PARSE_ERR);
	return (0);
}

int	validate_sides(char **tempmap)
{
	int	left;
	int	right;
	int	j;

	j = 6;
	while (tempmap[j] != NULL)
	{
		left = ft_firstoccur(tempmap[j], '1');
		right = ft_lastoccur(tempmap[j], '1');
		if ((tempmap[j][left] != '1' || tempmap[j][right] != '1') && \
		(tempmap[j][left] != 'x' || tempmap[j][right] != 'x'))
			return (PARSE_ERR);
		j++;
	}
	return (0);
}

int	validate_space(char **tempmap)
{
	int	i;
	int	j;

	j = 6;
	while (tempmap[j] != NULL)
	{
		i = 0;
		while (tempmap[j][i] != '\0')
		{
			if (ft_strchr("NSEW0", tempmap[j][i]))
			{
				if (!ft_strchr("NWSE01", tempmap[j][i + 1]) || \
					!ft_strchr("NWSE01", tempmap[j][i - 1]) || \
					!ft_strchr("NWSE01", tempmap[j - 1][i]) || \
					!ft_strchr("NWSE01", tempmap[j + 1][i]))
					return (PARSE_ERR);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	validate_vertices(char **tempmap, t_map *map)
{
	int	i;

	i = 0;
	while (tempmap[6][i] != '\0')
	{
		if (tempmap[6][i] != '1' && tempmap[6][i] != 'x')
			return (PARSE_ERR);
		i++;
	}
	i = 0;
	while (tempmap[map->high - 1][i] != '\0')
	{
		if (tempmap[map->high - 1][i] != '1' && \
		tempmap[map->high - 1][i] != 'x')
			return (PARSE_ERR);
		i++;
	}
	return (0);
}
