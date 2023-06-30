/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:16:57 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/27 19:15:12 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WHITE		"\033[0m"
# define YELLOW		"\033[1;33m"
# define GREEN		"\033[1;32m"
# define BLUE		"\033[1;34m"
# define CYAN		"\033[1;36m"
# define RED		"\033[1;31m"
# define PURPLE		"\033[0;35m"

/*-------- libft --------*/
# include "../libft/includes/libft.h"

/*-------- printf --------*/
# include "../libft/includes/pt_printf.h"

/*-------- get_next_line --------*/
# include "../libft/includes/get_next_line.h"

/*write, read, close, access, pipe, dup, dup2, execve and fork */
# include <unistd.h>

/*-------- printf, perror --------*/
# include <stdio.h>

/*-------- malloc, free and exit --------*/
# include <stdlib.h>

/*-------- open and unlink --------*/
# include <fcntl.h>

/*-------- sin and cos and tan--------*/
# include <math.h>

/*-------- bool -------*/
# include <stdbool.h>

/*-------- mlx --------*/
# include "../mlx/mlx.h"

/*-------- Header Files made --------*/
# include "structs.h"
# include "inputs.h"
# include "parsing.h"
# include "player.h"
# include "rendering.h"

/*-------- cub_utils.c --------*/
char	*cub_strtrim_free(char *line, char *set);
void	cub_place_image(t_window **win);
void	cub_prep_image(t_game *game, t_window **win, char flag);
void	free_double_array(char **arr);
int		return_error(char *str, t_map *map, t_game *game);

/*-------- cub_utls2.c --------*/
void	cub_return_error(char *str, t_map *map, t_game *game);

/*-------- cub_init.c --------*/
void	cub_draw(t_game *game);
void	cub_window_init(t_game *game, t_window *win);
void	cub_player_init(t_game *game);
void	cub_init(t_game *game);
void	cub_draw_floor_and_ceiling(t_game *game);

/*------- main.c -------*/
void	cub_get_textures(t_game *game, t_texture **tex, int i, char *dir);
void	cub_set_textures(t_game *game, t_map *map);

#endif