/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamphima <aamphima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:31:52 by aamphima          #+#    #+#             */
/*   Updated: 2024/11/13 17:41:27 by aamphima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!s && !d)
		return (0);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*int	main(int ac, char **av)
{
	char *s1;
	char *s2;

	if (ac == 4)
	{
		s1 = ft_memcpy(av[1], av[2], atoi(av[3]));
		s2 = memcpy(av[1], av[2], atoi(av[3]));
		printf("%s\n%s\n", s1, s2);
	}
	return (0);
}*/