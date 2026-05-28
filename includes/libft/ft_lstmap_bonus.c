/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamphima <aamphima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:59:56 by aamphima          #+#    #+#             */
/*   Updated: 2024/11/21 13:59:20 by aamphima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*noeud;
	t_list	*liste;

	if (!lst || !del || !f)
		return (NULL);
	liste = NULL;
	while (lst)
	{
		noeud = ft_lstnew(f(lst->content));
		if (noeud == NULL)
		{
			ft_lstclear(&liste, del);
			return (NULL);
		}
		ft_lstadd_back(&liste, noeud);
		lst = lst->next;
	}
	return (liste);
}
// void	del(void *content)
// {
// 	if (content)
// 	{
// 		free(content);
// 		content = NULL;
// 	}
// }
// void	*test(void *content)
// {
// 	char	*str;
// 	char	*new_str;
// 	size_t	i;

// 	str = (char *)content;
// 	new_str = ft_calloc(sizeof(char), ft_strlen(str) + 1);
// 	if (!new_str)
// 		return (NULL);
// 	i = 0;
// 	while (str[i])
// 	{
// 		new_str[i] = ft_toupper(str[i]);
// 		i++;
// 	}
// 	new_str[i] = '\0';
// 	return ((void *)new_str);
// }
// // void	*test(void *str)
// // {
// // 	char	*s;
// // 	int		i;

// // 	i = 0;
// // 	s = (char *)str;
// // 	while (s[i])
// // 	{
// // 		if (s[i] >= 'a' && s[i] <= 'z')
// // 			s[i] -= 32;
// // 		i++;
// // 	}
// // 	return ((char *)s);
// // }
//  int	main(void)
// {
// 	t_list *un;
// 	t_list *deux;
// 	t_list *trois;
// 	t_list *new;
// 	t_list *current;

// 	un = ft_lstnew(ft_strdup("bonjour"));
// 	deux = ft_lstnew(ft_strdup("Au Revoir"));
// 	trois = ft_lstnew(ft_strdup("Alane"));

// 	un->next = deux;
// 	deux->next = trois;

// 	current = un;
// 	printf("Avant MAP :\n");
// 	while (current)
// 	{
// 		printf("%s\n", (char *)current->content);
// 		current = current->next;
// 	}

// 	new = ft_lstmap(un, test, del);
// 	current = new;
// 	printf("Apres MAP :\n");
// 	while (current)
// 	{
// 		printf("%s\n", (char *)current->content);
// 		current = current->next;
// 	}

// 	ft_lstclear(&un, del);
// 	ft_lstclear(&new, del);
// 	return (0);
// }