/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamphima <aamphima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:10:48 by aamphima          #+#    #+#             */
/*   Updated: 2024/11/19 11:38:59 by aamphima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	calc_size(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len = 1;
	}
	if (n == 0)
		len = 1;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		len;

	nb = (long)n;
	len = calc_size(nb);
	str = ft_calloc(sizeof(char), len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (nb < 0)
	{
		nb = -nb;
		str[0] = '-';
	}
	while (len > 0)
	{
		if (nb == 0 && str[0] == '-')
			break ;
		str[len - 1] = nb % 10 + 48;
		nb = nb / 10;
		len--;
	}
	return (str);
}
// int	main(int ac, char **av)
// {
// 	char *str;
// 	str = ft_itoa(ft_atoi(av[1]));
// 	if (ac == 2)
// 		printf("%s\n", str);
// 	return (0);
// }