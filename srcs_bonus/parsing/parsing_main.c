/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadeluge <nadeluge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:57:37 by nadeluge          #+#    #+#             */
/*   Updated: 2026/02/04 12:37:51 by nadeluge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_map(t_cub *cub, char *path)
{
	int		len;
	char	*ext_check;

	len = ft_strlen(path);
	ext_check = ft_strdup(&path[len - 4]);
	if (ft_strncmp(ext_check, ".cub", 4) != 0)
	{
		free(ext_check);
		exit_error("Invalid map extension");
	}
	free(ext_check);
	cub->map.path = path;
	cub->player.pos.x = -1;
	cub->player.pos.y = -1;
	cub->map.fd = open(path, O_RDONLY);
	if (cub->map.fd == -1)
		exit_error("Invalid path to map");
	cub->graphic.ceiling.r = -1;
	cub->graphic.floor.r = -1;
}

void	choose_line(char *line, t_cub *cub, int *count, bool *start)
{
	if (!line || line[0] == '\n')
	{
		if (*start == true)
		{
			free(line);
			read_all_file(cub);
			free_cub(cub);
			exit_error("Wrong map : new line in the middle\n");
		}
	}
	else if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "WE", 2) == 0
		|| ft_strncmp(line, "SO", 2) == 0 || ft_strncmp(line, "EA", 2) == 0
		|| ft_strncmp(line, "DO", 2) == 0)
		parse_texture(line, cub);
	else if (ft_strncmp(line, "C", 1) == 0 || ft_strncmp(line, "F", 1) == 0)
		parse_color(line, line[0], cub);
	else
		parse_line(line, cub, start, count);
	free(line);
}

int	parse_main(char *path, t_cub *cub)
{
	char	*line;
	int		count;
	bool	start;

	start = false;
	count = 0;
	init_map(cub, path);
	line = get_next_line(cub->map.fd);
	while (line)
	{
		choose_line(line, cub, &count, &start);
		count++;
		line = get_next_line(cub->map.fd);
	}
	close(cub->map.fd);
	if (cub->graphic.ceiling.r == -1 || cub->graphic.floor.r == -1)
		clean_exit(cub, "no color for ceiling or floor\n");
	if (cub->player.pos.x == -1 || cub->player.pos.y == -1)
		clean_exit(cub, "No spawn location\n");
	if (check_map_close(cub) == false)
		clean_exit(cub, "Map is not closed !\n");
	if (cub->graphic.ea_path == NULL || cub->graphic.we_path == NULL
		|| cub->graphic.no_path == NULL || cub->graphic.so_path == NULL)
		clean_exit(cub, "Not all textures !\n");
	return (0);
}
