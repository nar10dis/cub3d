/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamphima <aamphima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:08:34 by aamphima          #+#    #+#             */
/*   Updated: 2024/11/13 12:53:53 by aamphima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// copy source to dest de taille n

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

/*int	main(int ac, char **av)
{
	size_t	str;
	char 	str1[] = "Hello";
	char	str2[] = "Alane";

	str = ft_strlcpy(str1, str2, 2);
	printf("%zu", str);
	return (0);
}*/
