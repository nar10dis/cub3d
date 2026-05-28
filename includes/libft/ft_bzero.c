/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamphima <aamphima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:07:54 by aamphima          #+#    #+#             */
/*   Updated: 2024/11/15 15:22:16 by aamphima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*c;

	c = s;
	while (n > 0)
	{
		*c = 0;
		c++;
		n--;
	}
}

/*int	main(void)
{
	char	str[10] = "BONJOURFDP";

	printf("avant bzero = %s\n", str);
	ft_bzero(str, 5);
	printf("apres bzero = %s", str);
	return (0);
}*/
