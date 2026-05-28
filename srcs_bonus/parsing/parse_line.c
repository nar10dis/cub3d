/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadeluge <nadeluge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 21:50:29 by nadeluge          #+#    #+#             */
/*   Updated: 2026/02/03 12:59:13 by nadeluge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_dir_la_suite(t_player *player, char *dir)
{
	if (dir[0] == 'W')
	{
		player->dir.x = -1;
		player->dir.y = 0;
		player->plane.x = 0;
		player->plane.y = -0.66;
	}
	else if (dir[0] == 'E')
	{
		player->dir.x = 1;
		player->dir.y = 0;
		player->plane.x = 0;
		player->plane.y = 0.66;
	}
}

void	set_dir(t_player *player, char *dir)
{
	if (dir[0] == 'N')
	{
		player->dir.x = 0;
		player->dir.y = -1;
		player->plane.x = 0.66;
		player->plane.y = 0;
	}
	else if (dir[0] == 'S')
	{
		player->dir.x = 0;
		player->dir.y = 1;
		player->plane.x = -0.66;
		player->plane.y = 0;
	}
	set_dir_la_suite(player, dir);
}

bool	check_valid_char(char *line, t_player *player, int count)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N' && line[i] != 'W'
			&& line[i] != 'E' && line[i] != 'S' && line[i] != 'D'
			&& line[i] != ' ' && line[i] != '\n')
			return (printf("Wrong char in line : '%c'\n", line[i]), false);
		if (ft_strchr("NSWE", line[i]))
		{
			if (player->pos.x == -1 || player->pos.y == -1)
			{
				(*player).pos.x = i + 0.5;
				(*player).pos.y = count + 0.5;
				set_dir(player, ft_strchr("NSWE", line[i]));
			}
			else
				return (printf("Must have one spawn\n"), false);
		}
		i++;
	}
	return (true);
}

void	parse_line(char *line, t_cub *cub, bool *start, int *count)
{
	if (check_valid_char(line, &cub->player, *count) == false)
	{
		free(line);
		read_all_file(cub);
		free_cub(cub);
		exit_error(NULL);
	}
	if (*start == false)
	{
		map_init(cub, get_line_nbr(cub->map.fd));
		reset_fd(cub, *count);
		*count = 0;
		*start = true;
	}
	skip_spaces(line);
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	cub->map.map[*count] = ft_strdup(line);
	cub->map.map[*count + 1] = NULL;
	cub->map.width[*count] = ft_strlen(line) - 1;
}
