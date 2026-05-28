/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadeluge <nadeluge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:06:31 by alane.a           #+#    #+#             */
/*   Updated: 2026/02/04 12:39:32 by nadeluge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static double	get_wall_dist_and_x(t_cub *cub, t_ray *ray, t_wall *wall)
{
	double	wall_x;

	if (ray->side == HORIZONTAL)
	{
		wall->dist = ray->next_dist.x - ray->step.x;
		wall_x = cub->player.pos.y + wall->dist * ray->dir.y;
	}
	else
	{
		wall->dist = ray->next_dist.y - ray->step.y;
		wall_x = cub->player.pos.x + wall->dist * ray->dir.x;
	}
	return (wall_x);
}

static void	get_wall_texture(t_cub *cub, t_ray *ray, t_wall *wall)
{
	if (ray->side == HORIZONTAL)
	{
		if (ray->dir.x > 0)
			wall->texture = cub->graphic.ea_tex;
		else
			wall->texture = cub->graphic.we_tex;
	}
	else
	{
		if (ray->dir.y > 0)
			wall->texture = cub->graphic.so_tex;
		else
			wall->texture = cub->graphic.no_tex;
	}
}

static void	get_wall_projection(t_cub *cub, t_wall *wall, double wall_x)
{
	wall_x -= floor(wall_x);
	wall->tex_x = (int)(wall_x * wall->texture.width);
	if (wall->tex_x < 0)
		wall->tex_x = 0;
	if (wall->tex_x >= wall->texture.width)
		wall->tex_x = wall->texture.width - 1;
	wall->height = (int)(cub->graphic.w_height / wall->dist);
	wall->start = -wall->height / 2 + cub->graphic.w_height / 2;
	if (wall->start < 0)
		wall->start = 0;
	wall->end = wall->height / 2 + cub->graphic.w_height / 2;
	if (wall->end >= cub->graphic.w_height)
		wall->end = cub->graphic.w_height - 1;
}

void	get_wall(t_cub *cub, t_ray *ray, t_wall *wall)
{
	double	wall_x;

	wall_x = get_wall_dist_and_x(cub, ray, wall);
	get_wall_texture(cub, ray, wall);
	get_wall_projection(cub, wall, wall_x);
}
