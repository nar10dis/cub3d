/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamphima <aamphima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:40:10 by aamphima          #+#    #+#             */
/*   Updated: 2024/11/13 17:33:09 by aamphima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// concatene src to dest de taille size

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_s;
	size_t	len_d;

	i = 0;
	j = 0;
	len_s = ft_strlen(src);
	len_d = ft_strlen(dest);
	if (size <= ft_strlen(dest))
		return (len_s + size);
	while (dest[i])
		i++;
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (len_d + len_s);
}

/*int	main(int ac, char **av)
{
	int str1;

	str1 = ft_strlcat(av[1], av[2], atoi(av[3]));
	if (ac == 4)
	{
		printf("%d, %d\n", (int)(ft_strlen(av[1])), (int)ft_strlen(av[2]));
		printf("%d\n", str1);
	}
	return (0);
}*/
