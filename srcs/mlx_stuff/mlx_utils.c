/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadeluge <nadeluge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:38:20 by nadeluge          #+#    #+#             */
/*   Updated: 2026/02/02 16:28:21 by nadeluge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	img_pix_put(t_cub *cub, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= cub->graphic.w_width || y < 0
		|| y >= cub->graphic.w_height)
		return ;
	pixel = cub->img.addr + (y * cub->img.line_len + x * (cub->img.bpp / 8));
	*(int *)pixel = color;
}

int	get_texture_color(t_texture *texture, int x, int y)
{
	char	*pixel;

	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return (0);
	pixel = texture->addr + (y * texture->line_len + x * (texture->bpp / 8));
	return (*(int *)pixel);
}
