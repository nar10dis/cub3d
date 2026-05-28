/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamphima <aamphima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:44:42 by aamphima          #+#    #+#             */
/*   Updated: 2024/11/19 13:57:16 by aamphima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
// int	main(int ac, char **av)
// {
// 	int fd;

// 	fd = open(av[1], O_WRONLY);
// 	if (ac == 3)
// 		ft_putendl_fd(av[2], fd);
// 	return (0);
// }