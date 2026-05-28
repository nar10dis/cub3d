/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadeluge <nadeluge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:50:17 by nadeluge          #+#    #+#             */
/*   Updated: 2026/02/02 16:28:10 by nadeluge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	rotate_camera(t_cub *cub, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->player.dir.x;
	old_plane_x = cub->player.plane.x;
	cub->player.dir.x = cub->player.dir.x * cos(angle) - cub->player.dir.y
		* sin(angle);
	cub->player.dir.y = old_dir_x * sin(angle) + cub->player.dir.y * cos(angle);
	cub->player.plane.x = cub->player.plane.x * cos(angle) - cub->player.plane.y
		* sin(angle);
	cub->player.plane.y = old_plane_x * sin(angle) + cub->player.plane.y
		* cos(angle);
}

int	is_wall(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'D')
		return (1);
	return (0);
}

int	can_move(t_cub *cub, double x, double y)
{
	if (is_wall(cub->map.map, (int)(x + COLLAPSE), (int)(y + COLLAPSE)))
		return (0);
	if (is_wall(cub->map.map, (int)(x - COLLAPSE), (int)(y + COLLAPSE)))
		return (0);
	if (is_wall(cub->map.map, (int)(x + COLLAPSE), (int)(y - COLLAPSE)))
		return (0);
	if (is_wall(cub->map.map, (int)(x - COLLAPSE), (int)(y - COLLAPSE)))
		return (0);
	return (1);
}

void	get_next_pos(double *x, double *y, t_cub *cub, int dir)
{
	if (dir == W)
	{
		*x += MOVESPEED * cub->player.dir.x;
		*y += MOVESPEED * cub->player.dir.y;
	}
	else if (dir == S)
	{
		*x -= MOVESPEED * cub->player.dir.x;
		*y -= MOVESPEED * cub->player.dir.y;
	}
	else if (dir == D)
	{
		*x -= MOVESPEED * cub->player.dir.y;
		*y += MOVESPEED * cub->player.dir.x;
	}
	else if (dir == A)
	{
		*x += MOVESPEED * cub->player.dir.y;
		*y -= MOVESPEED * cub->player.dir.x;
	}
}

void	move_player(t_cub *cub, int dir)
{
	double	new_x;
	double	new_y;

	new_x = cub->player.pos.x;
	new_y = cub->player.pos.y;
	get_next_pos(&new_x, &new_y, cub, dir);
	if (can_move(cub, cub->player.pos.x, new_y))
		cub->player.pos.y = new_y;
	if (can_move(cub, new_x, cub->player.pos.y))
		cub->player.pos.x = new_x;
}
