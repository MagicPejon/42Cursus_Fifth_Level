/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spacecount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:40:58 by gchernys          #+#    #+#             */
/*   Updated: 2023/05/04 09:41:35 by gchernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	spacecount(char *str, int i)
{
	int	count;

	count = 0;
	while (ft_space(str[i]))
	{
		count++;
		i++;
	}
	return (count);
}
