/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadeluge <nadeluge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:24:43 by aamphima          #+#    #+#             */
/*   Updated: 2026/02/03 13:07:02 by nadeluge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_map_scale(t_cub *cub, int map_width, int map_height)
{
	int	scale_x;
	int	scale_y;

	map_width++;
	scale_x = ((cub->graphic.w_width - 2 * cub->graphic.minimap.offset_x)
			/ map_width);
	scale_y = ((cub->graphic.w_height - 2 * cub->graphic.minimap.offset_y)
			/ map_height);
	if (scale_x < scale_y)
		return (scale_x);
	return (scale_y);
}

void	put_square(t_cub *cub, int x, int y, int color)
{
	t_vector	p;
	t_vector	screen;
	int			scale;

	scale = cub->graphic.minimap.scale;
	screen.x = cub->graphic.minimap.offset_x + (x * scale);
	screen.y = cub->graphic.minimap.offset_y + (y * scale);
	p.y = 0;
	while (p.y < scale)
	{
		p.x = 0;
		while (p.x < scale)
		{
			img_pix_put(cub, p.x + screen.x, p.y + screen.y, color);
			p.x++;
		}
		p.y++;
	}
}

void	draw_circle(t_cub *cub, int radius, int color)
{
	t_vector	p;
	t_vector	screen;
	t_vector	center;

	screen.x = cub->graphic.minimap.offset_x + ((cub->player.pos.x - 0.5)
			* cub->graphic.minimap.scale);
	screen.y = cub->graphic.minimap.offset_y + ((cub->player.pos.y - 0.5)
			* cub->graphic.minimap.scale);
	center.x = screen.x + cub->graphic.minimap.scale / 2;
	center.y = screen.y + cub->graphic.minimap.scale / 2;
	p.y = -radius;
	while (p.y <= radius)
	{
		p.x = -radius;
		while (p.x <= radius)
		{
			if (p.x * p.x + p.y * p.y <= radius * radius)
				img_pix_put(cub, center.x + p.x, center.y + p.y, color);
			p.x++;
		}
		p.y++;
	}
}

void	display_plane(int scale, int offset_x, int offset_y, t_cub *cub)
{
	t_vector	plane_start;
	t_vector	plane_end;
	t_vector	start_pixel;
	t_vector	end_pixel;

	cub->player.pos.x -= 0.5;
	cub->player.pos.y -= 0.5;
	plane_start.x = cub->player.pos.x + cub->player.dir.x - cub->player.plane.x;
	plane_start.y = cub->player.pos.y + cub->player.dir.y - cub->player.plane.y;
	plane_end.x = cub->player.pos.x + cub->player.dir.x + cub->player.plane.x;
	plane_end.y = cub->player.pos.y + cub->player.dir.y + cub->player.plane.y;
	start_pixel.x = offset_x + cub->player.pos.x * scale + scale / 2;
	start_pixel.y = offset_y + cub->player.pos.y * scale + scale / 2;
	end_pixel.x = offset_x + plane_start.x * scale + scale / 2;
	end_pixel.y = offset_y + plane_start.y * scale + scale / 2;
	dda(cub, start_pixel, end_pixel, 0x00FF0);
	end_pixel.x = offset_x + plane_end.x * scale + scale / 2;
	end_pixel.y = offset_y + plane_end.y * scale + scale / 2;
	dda(cub, start_pixel, end_pixel, 0x00FF0);
	cub->player.pos.x += 0.5;
	cub->player.pos.y += 0.5;
}

int	display_minimap(t_cub *cub)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (cub->map.map[i])
	{
		j = 0;
		while (cub->map.map[i][j])
		{
			if (cub->map.map[i][j] == '1')
				color = 0xFFFFFF;
			else
				color = 0x808080;
			put_square(cub, j, i, color);
				j++;
		}
		i++;
	}
	draw_circle(cub, 5, 0xFF000);
	display_plane(cub->graphic.minimap.scale, cub->graphic.minimap.offset_x,
		cub->graphic.minimap.offset_y, cub);
	return (0);
}
