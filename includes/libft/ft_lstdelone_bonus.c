/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alane.a <alane.a@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:10:18 by alane.a           #+#    #+#             */
/*   Updated: 2024/11/20 16:32:46 by alane.a          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (del && lst)
	{
		del(lst->content);
		free(lst);
	}
}

// int	main(void)
// {
// 	t_list *element;
// 	element = ft_lstnew("BONJOUR");
// 	printf("Avant Suppresion :\n");
// 	printf("%s\n", (char *)element->content);
// 	ft_lstdelone(element);
// 	printf("Apres Suppression :\n");
// 	printf("%s\n", (char *)element->content);;
// 	return (0);
// }