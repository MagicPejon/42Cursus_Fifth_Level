/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:47:29 by amalbrei          #+#    #+#             */
/*   Updated: 2023/04/27 17:51:21 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds double quotation marks to the value of the declared environment
 * variable
 * 
 * @param value The value to be double quoted
 * @return char* The value with double quotes
 */
char	*ft_quotes(char *value)
{
	value = ft_free_strjoin("\"", value, 3);
	value = ft_free_strjoin(value, "\"", 1);
	return (value);
}
