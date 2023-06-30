/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_separate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:32:25 by amalbrei          #+#    #+#             */
/*   Updated: 2023/04/27 17:46:51 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Separates the target of export to gain the value portion of the 
 * environment variable struct
 * 
 * @param target The target containing the value
 * @return char* The value of the environment variable
 */
char	*ft_separate(char *target, char sep)
{
	int		i;
	int		len;
	char	*value;

	i = 0;
	value = ft_strchr(target, sep) + 1;
	len = ft_strlen(value);
	while (1)
	{
		if (target[i] == sep)
		{
			i++;
			break ;
		}
		i++;
	}
	if (*value == '\0')
		value = ft_strdup("\0");
	else
		value = ft_substr(target, i, len);
	ft_bzero(&target[i], len);
	return (value);
}
