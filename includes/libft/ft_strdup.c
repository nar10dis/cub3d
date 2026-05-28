/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamphima <aamphima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:42:43 by aamphima          #+#    #+#             */
/*   Updated: 2025/09/22 14:46:20 by aamphima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		size;

	size = ft_strlen(s);
	dest = malloc(sizeof(char) * size + 1);
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s, (size + 1));
	return (dest);
}

/*int	main(int ac, char **av)
{
	char *str;
	str = NULL;

	if (ac == 2)
		str = ft_strdup(av[1]);
	printf("%s", str);
	free(str);
	return (0);
}*/