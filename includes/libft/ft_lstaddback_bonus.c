/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamphima <aamphima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:06:33 by aamphima          #+#    #+#             */
/*   Updated: 2024/11/21 13:40:16 by aamphima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst)
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
	else
		*lst = new;
}
// int	main(void)
// {
// 	t_list *un;
// 	t_list *deux;
// 	t_list *new;
// 	t_list *current;

// 	un = ft_lstnew("BONJOUR");
// 	deux = ft_lstnew("AUREVOIR");

// 	un->next = deux;

// 	current = un;
// 	printf("Avant addback :\n");
// 	while (current)
// 	{
// 		printf("%s\n", (char *)current->content);
// 		current = current->next;
// 	}

// 	current = un;
// 	new = ft_lstnew("ALANE");
// 	ft_lstadd_back(&un, new);
// 	while (current)
// 	{
// 		printf("%s\n", (char *)current->content);
// 		current = current->next;
// 	}
// 	return (0);
// }