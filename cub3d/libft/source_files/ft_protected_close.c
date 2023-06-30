/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_protected_close.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:50:50 by amalbrei          #+#    #+#             */
/*   Updated: 2023/04/27 17:53:20 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Ensures if the fds are different than the standard input, standard
 * output, the fail fd and the default fd before closing to avoid issues
 * 
 * @param fd The file descriptor to close
 * @param fail The number a file descriptor would have if it fails to open
 * @param def The default file descriptor set by the programmer
 */
void	ft_protected_close(int fd, int fail, int def)
{
	if (fd != STDIN_FILENO && fd != STDOUT_FILENO && fd != fail && fd != def)
		close(fd);
}
