# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nadeluge <nadeluge@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/28 14:54:52 by nadeluge          #+#    #+#              #
#    Updated: 2026/02/04 12:35:05 by nadeluge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = cub3D
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iincludes -Iincludes/libft -Iincludes/minilibx-linux
#CFLAGS      = -Wall -Wextra -Werror -Iincludes -Iincludes/libft -Iincludes/minilibx-mac
SRC_DIR     = srcs
OBJ_DIR     = objs

# Debug flags
ifdef DEBUG
    CFLAGS += -g3 -DDEBUG=1
    OBJ_DIR = objs_debug
endif

SRCS			= srcs/main.c \
				  srcs/free.c \
				  srcs/mlx_stuff/handle_hook.c \
				  srcs/mlx_stuff/handle_hook_2.c \
				  srcs/mlx_stuff/mlx_init.c \
				  srcs/mlx_stuff/mlx_utils.c \
				  srcs/parsing/parse_line.c \
				  srcs/parsing/parsing_graphic.c \
				  srcs/parsing/parsing_main.c \
				  srcs/parsing/parsing_map.c \
				  srcs/parsing/parsing_utils.c \
				  srcs/parsing/parsing_utils_2.c \
				  srcs/parsing/debug_parse_map.c \
				  srcs/graphics/dda.c \
				  srcs/graphics/draw_wall.c \
				  srcs/graphics/get_wall.c \
				  srcs/graphics/graphic_utils.c \
				  srcs/graphics/raycasting.c

SRCS_BONUS			= srcs_bonus/main.c \
				  srcs_bonus/free.c \
				  srcs_bonus/mlx_stuff/handle_hook.c \
				  srcs_bonus/mlx_stuff/handle_hook_2.c \
				  srcs_bonus/mlx_stuff/mlx_init.c \
				  srcs_bonus/mlx_stuff/mlx_utils.c \
				  srcs_bonus/parsing/parse_line.c \
				  srcs_bonus/parsing/parsing_graphic.c \
				  srcs_bonus/parsing/parsing_main.c \
				  srcs_bonus/parsing/parsing_map.c \
				  srcs_bonus/parsing/parsing_utils.c \
				  srcs_bonus/parsing/parsing_utils_2.c \
				  srcs_bonus/parsing/debug_parse_map.c \
				  srcs_bonus/graphics/dda.c \
				  srcs_bonus/graphics/draw_wall.c \
				  srcs_bonus/graphics/get_wall.c \
				  srcs_bonus/graphics/graphic_utils.c \
				  srcs_bonus/graphics/print_minimap.c \
				  srcs_bonus/graphics/raycasting.c

OBJ = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_BONUS = $(SRCS_BONUS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)


LIBFT_DIR   = includes/libft
LIBFT       = $(LIBFT_DIR)/libft.a
MLX_DIR     = includes/minilibx-linux
#MLX_DIR     = includes/minilibx-mac
MLX         = $(MLX_DIR)/libmlx.a
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
#MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit  #mac


all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# .NOTPARALLEL:
$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -rf objs objs_debug
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean || true

re: fclean all

debug:
	$(MAKE) DEBUG=1

bonus: $(LIBFT) $(MLX) $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

.PHONY: all clean fclean re debug bonus
