/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadeluge <nadeluge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:14:52 by alane.a           #+#    #+#             */
/*   Updated: 2026/02/03 16:42:11 by nadeluge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	dda_step(t_ray *ray)
{
	if (ray->next_dist.x < ray->next_dist.y)
	{
		ray->next_dist.x += ray->step.x;
		ray->map_x += ray->map_step_x;
		ray->side = HORIZONTAL;
	}
	else
	{
		ray->next_dist.y += ray->step.y;
		ray->map_y += ray->map_step_y;
		ray->side = VERTICAL;
	}
}

static int	out_of_map(t_cub *cub, t_ray *ray)
{
	if (ray->map_y < 0 || ray->map_y >= cub->map.height)
		return (1);
	if (ray->map_x < 0 || ray->map_x >= cub->map.width[ray->map_y])
		return (1);
	return (0);
}

void	go_to_wall(t_cub *cub, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		dda_step(ray);
		if (out_of_map(cub, ray))
			hit = 1;
		else if (cub->map.map[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}
