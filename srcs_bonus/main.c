/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadeluge <nadeluge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:29:56 by aamphima          #+#    #+#             */
/*   Updated: 2026/02/03 15:49:06 by nadeluge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	clean_exit(t_cub *cub, char *msg)
{
	if (msg)
	{
		write(2, "Error\n", 6);
		write(2, msg, ft_strlen(msg));
		write(2, "\n", 1);
	}
	free_cub(cub);
	exit(1);
}

void	exit_error(char *msg)
{
	if (!msg)
		exit(1);
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(1);
}

void	load_mlx(t_cub *cub)
{
	cub->mlx = mlx_init();
	cub->graphic.w_width = WIN_W;
	cub->graphic.w_height = WIN_H;
	cub->win = mlx_new_window(cub->mlx, cub->graphic.w_width,
			cub->graphic.w_height, "cub3d Minimap");
	cub->img.mlx_img = mlx_new_image(cub->mlx,
			cub->graphic.w_width, cub->graphic.w_height);
	cub->img.addr = mlx_get_data_addr(cub->img.mlx_img,
			&cub->img.bpp, &cub->img.line_len, &cub->img.endian);
	load_texture(cub, &cub->graphic.no_tex, cub->graphic.no_path);
	load_texture(cub, &cub->graphic.so_tex, cub->graphic.so_path);
	load_texture(cub, &cub->graphic.we_tex, cub->graphic.we_path);
	load_texture(cub, &cub->graphic.ea_tex, cub->graphic.ea_path);
	if (cub->graphic.door_path)
		load_texture(cub, &cub->graphic.door_tex, cub->graphic.door_path);
	get_graphic_stuff(cub);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac != 2)
		exit_error("Usage: ./cub3d map.cub");
	ft_bzero(&cub, sizeof(cub));
	parse_main(av[1], &cub);
	load_mlx(&cub);
	mlx_hook(cub.win, 2, 1L << 0, handle_keypress, &cub);
	mlx_hook(cub.win, 6, 1L << 6, mouse_move, &cub);
	mlx_hook(cub.win, 17, 0, handle_close, &cub);
	mlx_loop_hook(cub.mlx, raycasting, &cub);
	mlx_loop(cub.mlx);
	free_cub(&cub);
	return (0);
}
