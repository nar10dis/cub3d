/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadeluge <nadeluge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:01:38 by nadeluge          #+#    #+#             */
/*   Updated: 2026/02/03 15:58:35 by nadeluge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	read_all_file(t_cub *cub)
{
	char	*line;

	line = get_next_line(cub->map.fd);
	while (line)
	{
		free(line);
		line = get_next_line(cub->map.fd);
	}
	close(cub->map.fd);
}

void	free_double_char(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	free(str);
}

void	free_graphics(t_cub *cub)
{
	if (cub->graphic.no_path)
		free(cub->graphic.no_path);
	if (cub->graphic.so_path)
		free(cub->graphic.so_path);
	if (cub->graphic.we_path)
		free(cub->graphic.we_path);
	if (cub->graphic.ea_path)
		free(cub->graphic.ea_path);
	if (cub->graphic.no_tex.img)
		mlx_destroy_image(cub->mlx, cub->graphic.no_tex.img);
	if (cub->graphic.so_tex.img)
		mlx_destroy_image(cub->mlx, cub->graphic.so_tex.img);
	if (cub->graphic.we_tex.img)
		mlx_destroy_image(cub->mlx, cub->graphic.we_tex.img);
	if (cub->graphic.ea_tex.img)
		mlx_destroy_image(cub->mlx, cub->graphic.ea_tex.img);
	if (cub->graphic.door_tex.img)
		mlx_destroy_image(cub->mlx, cub->graphic.door_tex.img);
}

void	free_mlx(t_cub *cub)
{
	if (cub->img.mlx_img)
		mlx_destroy_image(cub->mlx, cub->img.mlx_img);
	if (cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	if (cub->mlx)
	{
		mlx_destroy_display(cub->mlx);
		free(cub->mlx);
	}
}

void	free_cub(t_cub *cub)
{
	if (!cub)
		return ;
	free_graphics(cub);
	free_mlx(cub);
	if (cub->map.width)
		free(cub->map.width);
	if (cub->map.map)
		free_double_char(cub->map.map);
}
