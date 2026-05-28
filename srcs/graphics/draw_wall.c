/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alane.a <alane.a@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:11:27 by alane.a           #+#    #+#             */
/*   Updated: 2026/01/29 12:27:16 by alane.a          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	draw_ceiling(t_cub *cub, int x, int end)
{
	int	i;
	int	color;

	i = 0;
	color = rgb_to_int(cub->graphic.ceiling);
	while (i < end)
	{
		img_pix_put(cub, x, i, color);
		i++;
	}
	return (i);
}

static int	draw_wall_texture(t_cub *cub, int x, t_wall *wall, int i)
{
	int		color;
	int		tex_y;
	double	tex_pos;
	double	step;

	step = (double)wall->texture.height / wall->height;
	tex_pos = (wall->start - cub->graphic.w_height / 2 + wall->height / 2)
		* step;
	while (i < wall->end)
	{
		tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= wall->texture.height)
			tex_y = wall->texture.height - 1;
		color = get_texture_color(&wall->texture, wall->tex_x, tex_y);
		img_pix_put(cub, x, i++, color);
		tex_pos += step;
	}
	return (i);
}

static void	draw_floor(t_cub *cub, int x, int i)
{
	int	color;

	color = rgb_to_int(cub->graphic.floor);
	while (i < cub->graphic.w_height)
		img_pix_put(cub, x, i++, color);
}

void	draw_ver_line(t_cub *cub, int x, t_wall *wall)
{
	int	i;

	i = draw_ceiling(cub, x, wall->start);
	i = draw_wall_texture(cub, x, wall, i);
	draw_floor(cub, x, i);
}
