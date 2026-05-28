/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_parse_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamphima <aamphima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:46:05 by nadeluge          #+#    #+#             */
/*   Updated: 2026/02/03 11:30:49 by aamphima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_line(int max)
{
	int	i;

	i = 0;
	printf(" ");
	while (i++ < max)
		printf("_");
	printf("\n");
}

int	get_max_width(t_map *map)
{
	int	i;
	int	max_width;

	i = 0;
	max_width = ft_strlen(map->map[i]);
	while (map->map[i])
	{
		if (map->width[i] > max_width)
			max_width = map->width[i];
		i++;
	}
	return (max_width);
}

void	print_map_line(t_map *map, int i, int x, int y)
{
	int	j;
	int	max_width;

	max_width = get_max_width(map);
	j = 0;
	print_line(max_width * 7);
	while (map->map[i][j])
	{
		if (map->map[i][j] == 'N')
			printf(GREEN);
		else if (i == y && j == x)
			printf(RED);
		if (j == 0)
			printf("|  %c  |", map->map[i][j]);
		else
			printf("  %c  |", map->map[i][j]);
		printf(RESET);
		j++;
	}
	while (j <= max_width)
	{
		printf("     |");
		j++;
	}
	printf("\n");
}

void	print_map(t_map *map, int x, int y)
{
	int	i;
	int	max_width;

	i = 0;
	max_width = get_max_width(map);
	while (map->map[i])
	{
		print_map_line(map, i, x, y);
		i++;
	}
	print_line(max_width * 7);
}

// void	print_map(t_map *map, int x, int y)
// {
// 	int	i;
// 	int	j;
// 	int	max_width;

// 	max_width = get_max_width(map);
// 	i = 0;
// 	j = 0;
// 	while (map->map[i])
// 	{
// 		j = 0;
// 		print_line(max_width * 7);
// 		while (map->map[i][j])
// 		{
// 			if (map->map[i][j] == 'N')
// 				printf(GREEN);
// 			else if (i == y && j == x)
// 				printf(RED);
// 			if (j == 0)
// 				printf("|  %c  |", map->map[i][j]);
// 			else
// 				printf("  %c  |", map->map[i][j]);
// 			j++;
// 			printf(RESET);
// 		}
// 		while (j <= max_width)
// 		{
// 			printf("     |");
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// 	print_line(max_width * 7);
// }
