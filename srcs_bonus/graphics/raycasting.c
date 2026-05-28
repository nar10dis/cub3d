/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadeluge <nadeluge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:09:38 by nadeluge          #+#    #+#             */
/*   Updated: 2026/02/02 16:45:17 by nadeluge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	rgb_to_int(t_rgb rgb)
{
	int	color;

	color = rgb.r;
	color = (color << 8) + rgb.g;
	color = (color << 8) + rgb.b;
	return (color);
}

void	get_next_dist(t_cub *cub, t_ray *ray)
{
	if (ray->dir.x < 0)
	{
		ray->map_step_x = -1;
		ray->next_dist.x = (cub->player.pos.x - ray->map_x) * ray->step.x;
	}
	else
	{
		ray->map_step_x = 1;
		ray->next_dist.x = (ray->map_x + 1.0 - cub->player.pos.x) * ray->step.x;
	}
	if (ray->dir.y < 0)
	{
		ray->map_step_y = -1;
		ray->next_dist.y = (cub->player.pos.y - ray->map_y) * ray->step.y;
	}
	else
	{
		ray->map_step_y = 1;
		ray->next_dist.y = (ray->map_y + 1.0 - cub->player.pos.y) * ray->step.y;
	}
}

void	create_ray(t_cub *cub, t_ray *ray, int i)
{
	ray->point_x = 2.0 * i / (double)cub->graphic.w_width - 1.0;
	ray->dir.x = cub->player.dir.x + cub->player.plane.x * ray->point_x;
	ray->dir.y = cub->player.dir.y + cub->player.plane.y * ray->point_x;
	ray->map_x = (int)cub->player.pos.x;
	ray->map_y = (int)cub->player.pos.y;
	if (ray->dir.x == 0)
		ray->step.x = INT_MAX;
	else
		ray->step.x = fabs(1.0 / ray->dir.x);
	if (ray->dir.y == 0)
		ray->step.y = INT_MAX;
	else
		ray->step.y = fabs(1.0 / ray->dir.y);
	get_next_dist(cub, ray);
}

int	raycasting(void *param)
{
	t_cub	*cub;
	t_ray	ray;
	t_wall	wall;
	int		i;

	cub = (t_cub *)param;
	ft_bzero(cub->img.addr, cub->img.line_len * cub->graphic.w_height);
	i = 0;
	while (i < cub->graphic.w_width)
	{
		create_ray(cub, &ray, i);
		go_to_wall(cub, &ray);
		get_wall(cub, &ray, &wall);
		draw_ver_line(cub, i, &wall);
		i++;
	}
	display_minimap(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.mlx_img, 0, 0);
	return (0);
}
