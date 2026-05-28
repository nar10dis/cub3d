/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadeluge <nadeluge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:34:44 by nadeluge          #+#    #+#             */
/*   Updated: 2026/02/03 16:30:33 by nadeluge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	dda(t_cub *cub, t_vector start, t_vector end, int color)
{
	t_vector	diff;
	t_vector	incr;
	int			j;
	double		len;

	j = 0;
	diff.x = end.x - start.x;
	diff.y = end.y - start.y;
	if (fabs(diff.x) >= fabs(diff.y))
		len = fabs(diff.x);
	else
		len = fabs(diff.y);
	incr.x = diff.x / len;
	incr.y = diff.y / len;
	while (j < (int)len)
	{
		img_pix_put(cub, (int)round(start.x), (int)round(start.y), color);
		start.x += incr.x;
		start.y += incr.y;
		j++;
	}
}

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

void	get_graphic_stuff(t_cub *cub)
{
	cub->graphic.minimap.scale = get_map_scale(cub,
			get_max_width(&cub->map), cub->map.height) / 5;
	cub->graphic.minimap.offset_x = 0;
	cub->graphic.minimap.offset_y = 0;
}
