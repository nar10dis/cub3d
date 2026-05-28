/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadeluge <nadeluge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:56:49 by nadeluge          #+#    #+#             */
/*   Updated: 2026/02/04 12:38:38 by nadeluge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	flood_fill(char **map, t_map *struct_map, int i, int j)
{
	char	c;

	if (i < 0 || j < 0 || i >= struct_map->height || j > struct_map->width[i])
		return (false);
	c = map[i][j];
	if (c == '1' || c == 'D' || c == 'x')
		return (true);
	if (c == ' ' || c == '\0')
		return (false);
	map[i][j] = 'x';
	return ((flood_fill(map, struct_map, i + 1, j)
			&& flood_fill(map, struct_map, i, j + 1)
			&& flood_fill(map, struct_map, i - 1, j)
			&& flood_fill(map, struct_map, i, j - 1)));
}

// en mode FLOODFILL mgl
bool	check_map_close(t_cub *cub)
{
	char	**tmp;
	int		i;
	int		j;
	bool	res;

	i = cub->player.pos.y;
	i -= 0.5;
	j = cub->player.pos.x;
	j -= 0.5;
	tmp = cub->map.map;
	res = flood_fill(cub->map.map, &cub->map, i, j);
	cub->map.map = tmp;
	return (res);
}
