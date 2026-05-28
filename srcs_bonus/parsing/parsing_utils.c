/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadeluge <nadeluge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:52:41 by nadeluge          #+#    #+#             */
/*   Updated: 2026/02/03 13:08:03 by nadeluge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (false);
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '\n')
			i++;
		else
		{
			return (false);
		}
	}
	return (true);
}

void	skip_spaces(char *str)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
		(*str)++;
}

void	reset_fd(t_cub *cub, int count)
{
	char	*tmp;
	int		i;

	i = 0;
	close(cub->map.fd);
	cub->map.fd = open(cub->map.path, O_RDONLY);
	tmp = get_next_line(cub->map.fd);
	while (i < count)
	{
		free(tmp);
		tmp = get_next_line(cub->map.fd);
		i++;
	}
	free(tmp);
}

int	get_line_nbr(int fd)
{
	char	*tmp;
	int		count;

	count = 0;
	tmp = get_next_line(fd);
	while (tmp)
	{
		count++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	return (count);
}

void	map_init(t_cub *cub, int line_nbr)
{
	line_nbr++;
	cub->map.map = malloc(sizeof(char *) * (line_nbr + 1));
	if (!cub->map.map)
		exit_error("Malloc error\n");
	cub->map.height = line_nbr;
	cub->map.width = malloc(sizeof(int) * line_nbr);
	if (!cub->map.width)
		exit_error("malloc error\n");
	cub->map.map[line_nbr] = NULL;
}
