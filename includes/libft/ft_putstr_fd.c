/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamphima <aamphima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:10:24 by aamphima          #+#    #+#             */
/*   Updated: 2024/11/19 13:43:58 by aamphima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

// int	main(int ac, char **av)
// {
// 	int fd;
// 	if (ac == 3)
// 	{
// 		fd = open(av[1], O_WRONLY);
// 		ft_putstr_fd(av[2], fd);
// 	}
//	return (0);
// }