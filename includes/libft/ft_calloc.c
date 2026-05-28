/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamphima <aamphima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:08:23 by aamphima          #+#    #+#             */
/*   Updated: 2024/11/19 16:37:12 by aamphima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*m;
	size_t	array;

	if (size == 0)
		return (malloc(0));
	array = nmemb * size;
	if (size && (array / size) != nmemb)
		return (NULL);
	m = malloc(sizeof(char) * array);
	if (m == NULL)
		return (NULL);
	ft_bzero(m, array);
	return (m);
}
