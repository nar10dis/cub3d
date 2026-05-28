/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamphima <aamphima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:50:30 by aamphima          #+#    #+#             */
/*   Updated: 2024/11/12 16:15:34 by aamphima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	x;
	size_t			i;

	str = (unsigned char *)s;
	x = (unsigned char)c;
	i = 0;
	while (i < n && n > 0)
	{
		if (str[i] == x)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

/*int	main(int ac, char **av)
{
	(void)ac;

	char	*result;
	result = (char *)ft_memchr(av[1], (av[2][0]), (size_t)atoi(av[3]));

	if (result == NULL)
		printf("nous navons rien trouvey");
	else
		printf("%c trouvey a l'adresse %p", *result, result);
	return (0);
}*/