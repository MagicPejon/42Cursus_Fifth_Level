/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_info_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 13:28:57 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/27 23:34:35 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	cub_comma_count(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == ',')
			j++;
		i++;
	}
	return (j);
}
