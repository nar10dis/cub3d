/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadeluge <nadeluge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:57:50 by nadeluge          #+#    #+#             */
/*   Updated: 2026/02/03 13:07:47 by nadeluge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	load_texture(t_cub *cub, t_texture *texture, char *path)
{
	int	len;

	if (!path)
	{
		free_cub(cub);
		exit_error("No path for texture !\n");
	}
	len = ft_strlen(path);
	if (path[len - 1] == '\n')
		path[len - 1] = '\0';
	texture->img = mlx_xpm_file_to_image(cub->mlx, path, &texture->width,
			&texture->height);
	if (!texture->img)
	{
		free_cub(cub);
		exit_error("Error loading the xpm file");
	}
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->line_len, &texture->endian);
}
