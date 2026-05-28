/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamphima <aamphima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:02:13 by aamphima          #+#    #+#             */
/*   Updated: 2024/11/13 18:56:06 by aamphima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*str;
	unsigned char	l;
	size_t			i;

	str = (char *)s;
	l = (unsigned char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == l)
			return (&str[i]);
		i++;
	}
	if (str[i] == l)
		return (&str[i]);
	return (NULL);
}

/*int	main(int ac, char **av)
{
	char	*str;

	str = ft_strchr(av[1], av[2][0]);
	if (ac == 3)
	{
		printf("%s\n", str);
	}
	return (0);
}*/