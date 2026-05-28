/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadeluge <nadeluge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:44:19 by aamphima          #+#    #+#             */
/*   Updated: 2026/02/04 12:58:37 by nadeluge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# define ERROR -1

# define BLACK	"\x1b[30m"
# define RED		"\x1b[31m"
# define GREEN	"\x1b[32m"
# define YELLOW	"\x1b[33m"
# define BLUE	"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define RESET	"\x1b[37m"

# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364

# define W 119
# define A 97
# define S 115
# define D 100
# define E 101

# define VERTICAL -9
# define HORIZONTAL -8
# define ROTSPEED 0.08
# define MOVESPEED 0.1
# define COLLAPSE 0.15f
# define WIN_H 780
# define WIN_W 1280

# include "../includes/libft/libft.h"
# include "../includes/minilibx-linux/mlx.h"
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_vector
{
	double	x;
	double	y;
}			t_vector;

typedef struct s_ray
{
	double		point_x;
	double		wall_dist;
	int			side;
	t_vector	dir;
	int			map_x;
	int			map_y;
	int			map_step_x;
	int			map_step_y;
	t_vector	next_dist;
	t_vector	step;
}			t_ray;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}		t_texture;

typedef struct s_wall
{
	double		dist;
	double		height;
	int			color;
	int			start;
	int			end;

	double		tex_x;
	t_texture	texture;
}			t_wall;

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}			t_rgb;

typedef struct s_map
{
	char	**map;
	int		height;
	int		*width;
	int		fd;
	char	*path;
}			t_map;

typedef struct s_minimap
{
	int	offset_x;
	int	offset_y;
	int	scale;
}	t_minimap;

typedef struct s_graphic
{
	int			w_width;
	int			w_height;
	char		*no_path;
	t_texture	no_tex;
	char		*so_path;
	t_texture	so_tex;
	char		*we_path;
	t_texture	we_tex;
	char		*ea_path;
	t_texture	ea_tex;
	char		*door_path;
	t_texture	door_tex;
	t_rgb		floor;
	t_rgb		ceiling;
	t_minimap	minimap;
}			t_graphic;

typedef struct s_img
{
	void	*mlx_img;

	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_player
{
	t_vector	pos;
	t_vector	plane;
	t_vector	dir;
}			t_player;

typedef struct s_cub
{
	void		*mlx;
	void		*win;

	t_img		img;
	t_map		map;
	t_graphic	graphic;
	t_player	player;
}			t_cub;

/* ************************************************************************** */
/*                                 mlx_stuff                                  */
/* ************************************************************************** */
//handle_hook.c
int		mouse_move(int x, int y, t_cub *cub);
int		is_wall(char **map, int x, int y);
int		can_move(t_cub *cub, double x, double y);
void	move_player(t_cub *cub, int dir);
void	rotate_camera(t_cub *cub, double angle);
//handle_hook_2.c
int		handle_close(t_cub *cub);
int		handle_keypress(int keycode, t_cub *cub);
void	move_camera_key(t_cub *cub, int key);
void	open_door(t_cub *cub);
//mlx_init.c
void	load_texture(t_cub *cub, t_texture *texture, char *path);
//mlx_utils.c
void	img_pix_put(t_cub *cub, int x, int y, int color);
int		get_texture_color(t_texture *texture, int x, int y);
/* ************************************************************************** */
/*                                  parsing                                   */
/* ************************************************************************** */
//parsing_main.c
int		parse_main(char *path, t_cub *cub);
//parsing_info.c
void	parse_color(char *line, char c, t_cub *cub);
void	parse_texture(char *line, t_cub *cub);
//parse_line.c
void	parse_line(char *line, t_cub *cub, bool *start, int *count);
bool	check_valid_char(char *line, t_player *player, int count);
void	set_dir(t_player *player, char *dir);
void	set_dir_la_suite(t_player *player, char *dir);
//parsing_map.c
void	parse_map(int fd, t_cub *cub);
bool	check_map_close(t_cub *cub);
int		get_line_nbr(int fd);
void	map_init(t_cub *cub, int line_nbr);
int		get_max_width(t_map *map);
//parsing_utils.c
void	skip_spaces(char *str);
void	reset_fd(t_cub *cub, int count);
bool	ft_isnum(char *str);
//parsing_utils2.c
void	parse_exit(t_cub *cub, char *line, char **split, char *msg);
bool	check_color_error(char **split);
//free.c
void	free_double_char(char **str);
void	free_graphics(t_cub *cub);
void	free_cub(t_cub *cub);
void	read_all_file(t_cub *cub);
void	exit_error(char *msg);
void	clean_exit(t_cub *cub, char *msg);
/* ************************************************************************** */
/*                                  graphics                                  */
/* ************************************************************************** */
//graphic
void	dda(t_cub *cub, t_vector start, t_vector end, int color);
int		display_minimap(t_cub *cub);
void	get_graphic_stuff(t_cub *cub);
int		rgb_to_int(t_rgb rgb);
void	go_to_wall(t_cub *cub, t_ray *ray);
void	draw_ver_line(t_cub *cub, int x, t_wall *wall);
void	get_wall(t_cub *cub, t_ray *ray, t_wall *wall);
int		raycasting(void *param);
//graphic_utils
int		get_map_scale(t_cub *cub, int map_width, int map_height);
void	get_graphic_stuff(t_cub *cub);
int		get_map_scale(t_cub *cub, int map_width, int map_height);

#endif
