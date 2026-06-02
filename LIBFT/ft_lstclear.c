/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 11:42:51 by prashres          #+#    #+#             */
/*   Updated: 2026/05/15 12:36:05 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}
// void	del(void *content)
// { 
// 	free(content); 
// }

// int	main(void)
// {
// 	t_list	*list = NULL;

// 	ft_lstadd_back(&list, ft_lstnew(strdup("hello")));
// 	ft_lstadd_back(&list, ft_lstnew(strdup("world")));

// 	ft_lstclear(&list, del);

// 	printf("%s\n", list == NULL ? "list is NULL" : "list is not NULL");
// }