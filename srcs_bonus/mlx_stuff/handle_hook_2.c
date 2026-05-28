/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hook_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadeluge <nadeluge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:51:28 by alane.a           #+#    #+#             */
/*   Updated: 2026/02/04 12:37:30 by nadeluge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	handle_close(t_cub *cub)
{
	clean_exit(cub, NULL);
	return (0);
}

int	handle_keypress(int keycode, t_cub *cub)
{
	if (keycode == 53 || keycode == 65307)
		handle_close(cub);
	else if (keycode == LEFT || keycode == RIGHT)
		move_camera_key(cub, keycode);
	else if (keycode == W || keycode == A || keycode == S || keycode == D)
		move_player(cub, keycode);
	else if (keycode == E)
		open_door(cub);
	return (0);
}

void	move_camera_key(t_cub *cub, int key)
{
	if (key == LEFT)
		rotate_camera(cub, -ROTSPEED);
	else if (key == RIGHT)
		rotate_camera(cub, ROTSPEED);
}

void	open_door(t_cub *cub)
{
	int	x;
	int	y;

	x = (int)(cub->player.pos.x + cub->player.dir.x);
	y = (int)(cub->player.pos.y + cub->player.dir.y);
	if (y < 0 || y >= cub->map.height || x < 0 || x >= cub->map.width[y])
		return ;
	if (cub->map.map[y][x] == 'D')
		cub->map.map[y][x] = 'O';
	else if (cub->map.map[y][x] == 'O')
		cub->map.map[y][x] = 'D';
}

int	mouse_move(int x, int y, t_cub *cub)
{
	static int	last_x = -1;
	double		angle;

	(void)y;
	if (last_x == -1)
	{
		last_x = x;
		return (0);
	}
	angle = (x - last_x) * 0.003;
	rotate_camera(cub, angle);
	last_x = x;
	return (0);
}
