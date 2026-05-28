/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamphima <aamphima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:47:23 by aamphima          #+#    #+#             */
/*   Updated: 2025/09/19 14:49:14 by aamphima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamphima <aamphima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:49:43 by aamphima          #+#    #+#             */
/*   Updated: 2024/12/02 15:22:17 by aamphima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_strdup(const char *s)
// {
// 	char	*dest;
// 	int		size;

// 	size = ft_str_len(s);
// 	dest = malloc(sizeof(char) * (size + 1));
// 	if (dest == NULL)
// 		return (NULL);
// 	ft_strlcpy(dest, s, (size + 1));
// 	return (dest);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*dest;
// 	size_t		len;

// 	len = ft_str_len(s1) + ft_str_len(s2);
// 	dest = malloc(sizeof(char) * (len + 1));
// 	if (dest == NULL)
// 		return (NULL);
// 	ft_strlcpy(dest, s1, len + 1);
// 	ft_strlcat(dest, s2, len + 1);
// 	return (dest);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t		s_len;
// 	char	*str;

// 	if (s == NULL)
// 		return (NULL);
// 	s_len = ft_str_len(s);
// 	if (start >= (unsigned int)s_len)
// 	{
// 		str = malloc(sizeof(char) * 1);
// 		return (str);
// 	}
// 	if (len > s_len - (size_t)start)
// 		len = s_len - (size_t)start;
// 	str = malloc(sizeof(char) * len + 1);
// 	if (str == NULL)
// 		return (NULL);
// 	ft_strlcpy(str, &s[start], len + 1);
// 	return (str);
// }

// size_t	ft_strlcpy(char *dest, const char *src, size_t size)
// {
// 	size_t i;

// 	i = 0;
// 	if (size == 0)
// 		return (ft_str_len(src));
// 	while (src[i] && i < size - 1)
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (ft_str_len(src));
// }

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_s;
	size_t	len_d;

	i = 0;
	j = 0;
	len_s = ft_str_len(src);
	len_d = ft_str_len(dest);
	if (size <= ft_str_len(dest))
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
