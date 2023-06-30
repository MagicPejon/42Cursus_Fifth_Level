/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:16:48 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/28 15:19:23 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/***************************PARSING***************************/
int				malloc_map(t_map *map, char *file, t_game *game);
int				basic_error_check(int argc, char **argv);
int				load_map(t_game *game, t_map *map, char *file, int count);
int				validate_map(t_map *map, t_game *game, char *str, int fd);
int				validate_vertices(char **tempmap, t_map *map);
int				validate_space(char **tempmap);
int				validate_sides(char **tempmap);
int				validate_player_count(char **tempmap);
int				set_textures(t_map *map);
void			setmap(char **tempmap, t_map *map, t_game *game);
int				check_textures(t_map *map);
int				find_rgb(t_map *map);
int				init_rgb(t_map *map);
int				set_dimensions(t_map *map, t_game *game, char *file);
unsigned long	setrgb(int red, int green, int blue);
int				check_rgb(char **str);
void			load_grid_segments(t_game *game, char *temp, char *str);
void			fill_corners(t_game *game, int i, int j);
void			fill_corners_middle(t_game *game, int i, int j, int k);
void			fill_corners_end(t_game *game, int i, int j, int k);
char			**load_grid(t_game *game, int i, int x, int y);
void			fill_segments(t_game *game);
void			segment_init(t_game *game);
void			connect_segments(t_game *game);
void			connect_segments_p2(t_game *game, int i, int h, int v);
int				cub_comma_count(char *line);
int				cub_check_newlines(char *str);

#endif