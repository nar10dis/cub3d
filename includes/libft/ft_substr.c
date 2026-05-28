/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamphima <aamphima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:56:59 by aamphima          #+#    #+#             */
/*   Updated: 2024/11/19 14:39:01 by aamphima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*str;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= (unsigned int)s_len)
	{
		str = ft_calloc(sizeof(char), 1);
		return (str);
	}
	if (len > s_len - start)
		len = s_len - start;
	str = ft_calloc(sizeof(char), len + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, &s[start], len + 1);
	return (str);
}

/*int	main(int ac, char **av)
{
	char *str;
	if (ac == 4)
	{
		str = ft_substr(av[1], atoi(av[2]), (int)atoi(av[3]));
		printf("%s\n", str);
		free(str);
	}
	return (0);
}*/