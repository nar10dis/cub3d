/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamphima <aamphima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:07:14 by aamphima          #+#    #+#             */
/*   Updated: 2025/05/14 18:38:39 by aamphima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*b;
	char	*l;

	i = 0;
	b = (char *)big;
	l = (char *)little;
	if (l[0] == '\0')
		return (b);
	while (b[i] && i < len)
	{
		j = 0;
		while (b[i + j] == l[j] && (i + j) < len)
		{
			j++;
			if (l[j] == '\0')
				return (b + i);
		}
		i++;
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	char	*str;

	str = ft_strnstr(av[1], av[2], atoi(av[3]));
	if (ac == 4)
		printf("%s\n", str);
	return (0);
}
