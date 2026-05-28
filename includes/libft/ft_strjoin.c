/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamphima <aamphima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:21:26 by aamphima          #+#    #+#             */
/*   Updated: 2024/11/15 13:11:11 by aamphima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	dest = ft_calloc(sizeof(char), len + 1);
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s1, len + 1);
	ft_strlcat(dest, s2, len + 1);
	return (dest);
}

/*int	main(int ac, char **av)
{
	char *str;
	if (ac == 3)
	{
		str = ft_strjoin(av[1], av[2]);
		printf("%s\n", str);
		free(str);
	}
	return (0);
}*/