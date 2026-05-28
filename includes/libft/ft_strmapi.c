/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamphima <aamphima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:40:46 by aamphima          #+#    #+#             */
/*   Updated: 2024/11/19 12:34:23 by aamphima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dest;

	i = 0;
	dest = ft_calloc(sizeof(char), ft_strlen(s) + 1);
	if (dest == NULL)
		return (NULL);
	while (s[i])
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	return (dest);
}

// char	test(unsigned int i, char c)
// {
// 	if (c >= 'a' && c <= 'z')
// 		c -= 32;
// 	return (c);
// }

// int	main(void)
// {
// 	char	s[] = "Bonjour";
// 	char	*str;

// 	str = ft_strmapi(s, test);
// 	printf("%s\n", s);
// 	printf("%s\n", str);
// 	return (0);
// }
