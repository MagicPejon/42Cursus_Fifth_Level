/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lastoccur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 14:15:21 by gchernys          #+#    #+#             */
/*   Updated: 2023/04/25 15:35:13 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lastoccur(const char *str, char c)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i--;
	}
	return (0);
}
