/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamphima <aamphima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:47:10 by aamphima          #+#    #+#             */
/*   Updated: 2024/11/13 17:47:01 by aamphima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <ctype.h>

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

/*int	main(int ac, char **av)
{
	int o;
	int	i;

	o = ft_toupper(av[1][0]);
	i = toupper(av[1][0]);

	if (ac == 2)
	{
		printf("%d\n", o);
		printf("%d\n", i);
	}
	return (0);
}*/