# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/14 10:55:58 by amalbrei          #+#    #+#              #
#    Updated: 2023/06/28 11:07:16 by amalbrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

D				=	\033[0m
R				=	\033[1;31m
G				=	\033[1;32m
Y				=	\033[1;33m
P				=	\033[0;35m
C				=	\033[1;36m

NAME			=	cub3D
SUB_LIB			=	libft/libft.a
OBJ_DIR			=	object_files
INPUTS_DIR		=	inputs
PLAYER_DIR		=	player
RENDERING_DIR	=	rendering
PARSING_DIR		=	parsing
MAIN_DIR		=	source_files
MLX_DIR			=	-Imlx
INC_DIR 		=	-Iincludes -Ilibft/includes
LIB				=	ar	-rcs
LIBFT			=	-Llibft -lft
MLX				=	-Lmlx -lmlx
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -g3 -Ofast
CUB3D_FLAGS 	=	-framework OpenGL -framework AppKit
RM				=	rm	-rf

INPUTS_SRC 		=	cub_close_x.c	cub_inputs.c	cub_free.c	cub_press.c\
					cub_inputs_utils.c

INPUTS_SRC_B 		=	cub_close_x_bonus.c	cub_inputs.c	cub_free.c\
					cub_press_bonus.c	cub_inputs_utils.c\

PLAYER_SRC		=	cub_calc_player.c	cub_find_intersect.c\
					cub_find_player.c	cub_find_utils.c

PLAYER_SRC_B	=	cub_calc_player_bonus.c	cub_find_intersect.c\
					cub_find_player.c	cub_find_utils.c

RENDERING_SRC	=	cub_bressenham_mini.c	cub_draw_ui.c	cub_draw_map.c\
					cub_draw_column.c	cub_bressenham.c	cub_back_collisions.c\
					cub_render_utils.c

RENDERING_SRC_B	=	cub_bressenham_mini.c	cub_draw_ui.c	cub_draw_map.c\
					cub_draw_column_bonus.c	cub_bressenham.c\
					cub_back_collisions.c	cub_render_utils.c
					

PARSING_SRC		=	make_map.c	map_validation.c	parsing.c\
					textures_and_colors.c	segmentation.c	fill_segments.c\
					cub_info_check.c

PARSING_SRC_B	=	make_map.c	map_validation.c	parsing.c\
					textures_and_colors.c	segmentation_bonus.c\
					fill_segments.c			cub_info_check.c

MAIN_SRC 		=	main.c	cub_utils.c	cub_utils2.c	cub_init.c

MAIN_SRC_B 		=	main.c	cub_utils.c	cub_utils2_bonus.c	cub_init_bonus.c

SRC				=	$(INPUTS_SRC) $(PLAYER_SRC) $(RENDERING_SRC) $(PARSING_SRC)\
					$(MAIN_SRC)

SRC_B			=	$(INPUTS_SRC_B) $(PLAYER_SRC_B) $(RENDERING_SRC_B)\
					$(PARSING_SRC_B)	$(MAIN_SRC_B)

OBJ				= 	$(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

OBJ_BONUS		=	$(addprefix $(OBJ_DIR)/,$(SRC_B:%.c=%.o))

all: mlx $(SUB_LIB) $(NAME)

bonus: mlx $(SUB_LIB) bonus_c

mlx:
	@$(MAKE) all -C mlx

$(SUB_LIB):
	@printf "$(C)==========================\n"
	@printf "$(C)==========================\n"
	@printf "LIBFT COMPILATION START\n"
	@printf "$(C)==========================\n\n\n\n$(D)"
	@$(MAKE) libft.a -C libft
	@$(MAKE) bonus -C libft
	@$(MAKE) printf -C libft
	@$(MAKE) gnl -C libft
	@printf "$(C)==========================\n"
	@printf "LIBFT COMPILATION FINISHED\n"
	@printf "$(C)==========================\n"
	@printf "$(C)==========================\n\n$(D)"

$(OBJ_DIR)/%.o: $(INPUTS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf "\033[A\033[2K\r\033[A\033[2K\r$(G)Compiling:\n$(D)"
	$(CC) $(CFLAGS) $(INC_DIR) $(MLX_DIR)  -c $< -o $@

$(OBJ_DIR)/%.o: $(PLAYER_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf "\033[A\033[2K\r\033[A\033[2K\r$(G)Compiling:\n$(D)"
	$(CC) $(CFLAGS) $(INC_DIR) $(MLX_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(RENDERING_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf "\033[A\033[2K\r\033[A\033[2K\r$(G)Compiling:\n$(D)"
	$(CC) $(CFLAGS) $(INC_DIR) $(MLX_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(PARSING_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf "\033[A\033[2K\r\033[A\033[2K\r$(G)Compiling:\n$(D)"
	$(CC) $(CFLAGS) $(INC_DIR) $(MLX_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(MAIN_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf "\033[A\033[2K\r\033[A\033[2K\r$(G)Compiling:\n$(D)"
	$(CC) $(CFLAGS) $(INC_DIR) $(MLX_DIR) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(INC_DIR) $(OBJ) $(LIBFT) $(MLX) $(CUB3D_FLAGS) -o $(NAME)
	@printf "$(C)\n==========================\n"
	@printf "$(C) CUB3D COMPILED\n"
	@printf "$(C)==========================\n$(D)"

bonus_c: $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(INC_DIR) $(OBJ_BONUS) $(LIBFT) $(MLX) $(CUB3D_FLAGS) -o $(NAME)
	@printf "$(C)\n==========================\n"
	@printf "$(C) CUB3D COMPILED\n"
	@printf "$(C)==========================\n$(D)"

norm:
	@norminette | grep Error

valgrind: all
	@printf "$(P)Checking with valgrind...\n$(D)"
	@valgrind \
	--leak-check=full \
	--trace-children=yes \
	--show-leak-kinds=all \
	--track-origins=yes \
	--track-fds=yes \
	./cub3D

list:
	@$(MAKE) list -C libft

clean:
	@$(MAKE) clean -C mlx
	@$(MAKE) clean -C libft
	@$(RM) $(OBJ_DIR)
	@printf "$(R)CLEANING CUB.O FILES\n$(D)"

fclean: clean
	@$(MAKE) fclean -C libft
	@$(RM) $(NAME)
	@printf "$(R)CLEANING CUB3D PROGRAM\n$(D)"

re: fclean all

.PHONY: all mlx $(SUB_LIB) norm chirp valgrind list clean fclean re