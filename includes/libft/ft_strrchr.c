/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamphima <aamphima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:37:00 by aamphima          #+#    #+#             */
/*   Updated: 2024/11/19 12:41:49 by aamphima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if ((char)c == s[i])
			return ((char *)&s[i]);
		i--;
	}
	if ((char)c == s[i])
		return ((char *)&s[i]);
	return (NULL);
}

// int	main(int ac, char **av)
// {
// 	char	*src;
// 	char	*d1;
// 	char	*d2;

// 	src = "abbbbbbbb";
// 	d1 = strrchr(src, 'a');
// 	d2 = ft_strrchr(src, 'a');
// 	printf("%s\n", d1);
// 	printf("%s\n", d2);
// 	return (0);
// }
