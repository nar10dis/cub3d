/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_graphic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadeluge <nadeluge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:29:33 by aamphima          #+#    #+#             */
/*   Updated: 2026/02/03 12:56:44 by nadeluge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_color(t_rgb *color, char **split)
{
	long long	test;

	if (check_color_error(split) == false)
		return (1);
	test = ft_atoi(split[0]);
	if (test < INT_MIN || test > INT_MAX)
		return (1);
	color->r = (int)test;
	test = ft_atoi(split[1]);
	if (test < INT_MIN || test > INT_MAX)
		return (1);
	color->g = (int)test;
	test = ft_atoi(split[2]);
	if (test < INT_MIN || test > INT_MAX)
		return (1);
	color->b = (int)test;
	if (color->r < 0 || color->r > 255 || color->g < 0 || color->g > 255
		|| color->b < 0 || color->b > 255)
		return (1);
	return (0);
}

void	parse_color(char *line, char c, t_cub *cub)
{
	t_rgb	color;
	char	**split;
	int		i;

	i = 0;
	if (cub->graphic.ceiling.r != -1 && c == 'C')
		parse_exit(cub, line, NULL, "Multiple ceiling color");
	if (cub->graphic.floor.r != -1 && c == 'F')
		parse_exit(cub, line, NULL, "Multiple floor color");
	if (line[1] != ' ')
		parse_exit(cub, line, NULL, "Wrong color indentifier");
	split = ft_split(&line[2], ',');
	if (check_color(&color, split) == 1)
		parse_exit(cub, line, split, "Wrong rgb");
	while (split[i])
		free(split[i++]);
	free(split);
	if (c == 'C')
		cub->graphic.ceiling = color;
	else if (c == 'F')
		cub->graphic.floor = color;
}

static void	set_texture(t_cub *cub, char **dst, char *src, char *line)
{
	if (*dst != NULL)
		parse_exit(cub, line, NULL, "Multiple texture path");
	*dst = ft_strdup(src);
}

void	choose_texture(t_cub *cub, char **split, char *line)
{
	if (!ft_strncmp(split[0], "NO", 2))
		set_texture(cub, &cub->graphic.no_path, split[1], line);
	else if (!ft_strncmp(split[0], "SO", 2))
		set_texture(cub, &cub->graphic.so_path, split[1], line);
	else if (!ft_strncmp(split[0], "EA", 2))
		set_texture(cub, &cub->graphic.ea_path, split[1], line);
	else if (!ft_strncmp(split[0], "WE", 2))
		set_texture(cub, &cub->graphic.we_path, split[1], line);
	else if (!ft_strncmp(split[0], "DO", 2))
		set_texture(cub, &cub->graphic.door_path, split[1], line);
}

void	parse_texture(char *line, t_cub *cub)
{
	int		j;
	char	**split;

	j = 0;
	split = ft_split(line, ' ');
	while (split[j])
		j++;
	if (j != 2)
		parse_exit(cub, line, split, "Multiple texture path");
	if (!line || *line == '\0')
		return ;
	if (ft_strlen(split[0]) != 2)
		parse_exit(cub, line, split, "Wrong texture identifier");
	choose_texture(cub, split, line);
	free_double_char(split);
}
