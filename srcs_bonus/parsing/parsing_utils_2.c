/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadeluge <nadeluge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 21:52:10 by nadeluge          #+#    #+#             */
/*   Updated: 2026/02/03 12:56:25 by nadeluge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	parse_exit(t_cub *cub, char *line, char **split, char *msg)
{
	free_double_char(split);
	read_all_file(cub);
	free_cub(cub);
	if (line)
		free(line);
	exit_error(msg);
}

bool	check_color_error(char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
		{
			if (!ft_isnum(split[i]))
				return (false);
			i++;
		}
		if (i != 3)
			return (false);
	}
	return (true);
}
