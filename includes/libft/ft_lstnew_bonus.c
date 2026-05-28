/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamphima <aamphima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:58:43 by aamphima          #+#    #+#             */
/*   Updated: 2024/11/19 16:18:20 by aamphima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = ft_calloc(sizeof(t_list), 1);
	if (lst == NULL)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
// int	main(void)
// {
// 	char str[] = "BONJOUR";
// 	t_list *try = ft_lstnew(str);
// 	printf("%s\n", (char *)try->content);
// 	printf("%p\n", try->next);
// 	return (0);
// }