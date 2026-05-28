/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamphima <aamphima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:04:17 by aamphima          #+#    #+#             */
/*   Updated: 2024/11/21 11:32:52 by aamphima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// int	main(void)
// {
// 	t_list *un;
// 	t_list *deux;
// 	t_list *last;

// 	un = ft_lstnew("BONJOUR");
// 	deux = ft_lstnew("AUREVOIR");

// 	un->next = deux;

// 	last = ft_lstlast(un);
// 	printf("%s\n", (char *)last->content);
// 	return (0);
// }