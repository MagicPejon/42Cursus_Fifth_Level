/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:15:59 by amalbrei          #+#    #+#             */
/*   Updated: 2023/06/27 19:22:58 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

/*----- cub_back_collisions.c -----*/
void	cub_protect_boundaries_x(t_map *map, double *point);
void	cub_protect_boundaries_y(t_map *map, double *point);
double	cub_back_horizontal(t_map *map, t_player *player, char **full_grid,
			double angle);
double	cub_back_vertical(t_map *map, t_player *player, char **full_grid,
			double angle);
double	cub_back_collisions(t_game *game, t_player *player, double angle);

/*----- cub_bressenham_mini.c -----*/
void	my_mlx_pixel_put(t_game *game, int x, int y);
void	cub_bressenham_mini_decision(t_game *game, t_bress *bress, int i);
void	cub_bressenham_mini_frag(t_game *game, t_bress *bress, char *flag);
void	cub_bressenham_mini(int x, int y, t_game *game, char *flag);

/*----- cub_bressenham.c -----*/
void	cub_bressenham_decision(t_game *game, t_bress *bress, int i);
void	cub_bressenham_frag(t_game *game, t_bress *bress);
void	cub_realign(t_bress *bress, t_game *game);
void	cub_bressenham(double x, double y, double *delta, t_game *game);

/*----- cub_draw_ui.c -----*/
void	cub_draw_outline(t_game *game, t_bress bress);
void	cub_draw_cursor(t_game *game, t_player *player);
void	cub_turn_transparent(t_game *game, int width, int height, int *start);
void	cub_draw_ui(t_game *game);

/*----- cub_draw_map.c -----*/
void	cub_print_m_info(t_game *game);
void	cub_draw_grid_extra(t_game *game, char **grid, int x, int y);
int		cub_end_of_line(char *line);
void	cub_draw_grid(t_game *game, char **grid);
void	cub_draw_m_background(t_game *game, t_window *win);

/*----- cub_draw_column.c -----*/
int		cub_get_tex_colour(t_game *game, int i);
void	cub_put_column(t_game *game, int i, int draw_st, int draw_end);
void	cub_prep_column(t_game *game, t_player *player, t_window *win,
			t_texture **tex);
void	cub_correct_distance(t_game *game, t_player *player);
void	cub_draw_column(t_game *game, t_player *player, t_window *win);

/*----- cub_render_utils.c -----*/
void	cub_check_scaling(t_texture **tex, int i, int y);
int		cub_check_side(int side);

#endif