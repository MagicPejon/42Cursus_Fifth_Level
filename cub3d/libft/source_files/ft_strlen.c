/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:45:42 by amalbrei          #+#    #+#             */
/*   Updated: 2023/05/29 09:20:09 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Measures the size of a string
 * 
 * @param c The string to be measured
 * @return size_t The size of the string
 */
size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}
