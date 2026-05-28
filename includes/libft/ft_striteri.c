/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamphima <aamphima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:03:52 by aamphima          #+#    #+#             */
/*   Updated: 2024/11/19 12:34:19 by aamphima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void	test(unsigned int i, char *c)
// {
// 	i = 0;
// 	if (c[i] >= 'a' && c[i] <= 'z')
// 		c[i] -= 32;
// }

// int	main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		ft_striteri(av[1], test);
// 		printf("%s\n", av[1]);
// 	}
// 	return (0);
// }