/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamphima <aamphima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:09:01 by aamphima          #+#    #+#             */
/*   Updated: 2024/11/12 11:15:50 by aamphima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*n;

	n = (unsigned char *)b;
	while (len > 0)
	{
		*n = (unsigned char)c;
		n++;
		len--;
	}
	return ((void *)b);
}

/*int	main(void)
{
	int	c;
	char	str[8] = "Bonjour";

	c = '0';
	printf("Avant memset = %s\n", str);
	ft_memset(str, c, 7);
	printf("Apres memset = %s", str);
	return (0);
}*/
