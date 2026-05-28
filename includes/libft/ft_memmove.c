/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamphima <aamphima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:27:34 by aamphima          #+#    #+#             */
/*   Updated: 2024/11/13 19:50:44 by aamphima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	i = -1;
	if (!dst && !src)
		return (NULL);
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (d > s)
	{
		while (len > 0)
		{
			len--;
			d[len] = s[len];
		}
	}
	else
	{
		while (++i < len)
		{
			d[i] = s[i];
		}
	}
	return (dst);
}

/*int	main(void)
{
	char	*str2 = "nardis";
	char	str1[] = "Alane8cotheque";
	size_t s;

	s = 6;

	printf("Avant memmove : str1 = %s, str2 = %s\n", str1, str2);
	ft_memmove(str1, str2, s);
	printf("Apres memmove : str1 = %s, str2 = %s\n", str1, str2);

	char	overlapTest[] = "Overlap Test";
	//ft_memmove(overlapTest + 3, overlapTest, 7);
	//printf("Test de chevauchement1 : %s\n", overlapTest);
	memmove(overlapTest + 3, overlapTest, 7);
	printf("Test de chevauchement2 : %s\n", overlapTest);
	return (0);
}*/
