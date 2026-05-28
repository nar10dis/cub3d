/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hook_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadeluge <nadeluge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:51:28 by alane.a           #+#    #+#             */
/*   Updated: 2026/02/03 16:40:53 by nadeluge         ###   ########.fr       */
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
	return (0);
}

void	move_camera_key(t_cub *cub, int key)
{
	if (key == LEFT)
		rotate_camera(cub, -ROTSPEED);
	else if (key == RIGHT)
		rotate_camera(cub, ROTSPEED);
}
