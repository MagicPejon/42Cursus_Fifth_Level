/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:16:47 by amalbrei          #+#    #+#             */
/*   Updated: 2023/05/14 19:17:58 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_read(int fd, char *buf, int *loc);
char	*create_result(char *buf, int loc);
char	*fill_buf(char *buf, int loc);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strchr_gnl(char *str, int *i, int *give_loc);
int		ft_strlen_gnl(char *s);

#endif