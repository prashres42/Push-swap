/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 11:43:24 by prashres          #+#    #+#             */
/*   Updated: 2026/05/15 12:32:57 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	void	*content;
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		content = f(lst->content);
		node = ft_lstnew(content);
		if (!node)
		{
			del(content);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, node);
		lst = lst->next;
	}
	return (new);
}
// #include <stdio.h>
// void	*add_one(void *content)
// {
// 	int	*new;

// 	new = malloc(sizeof(int));
// 	*new = *(int *)content + 1;
// 	return (new);
// }
// void	del(void *content)
// { 
// 	free(content); 
// }
// int	main(void)
// {
// 	size_t i = 0;
// 	int		vals[] = {1, 2, 3};
// 	t_list	*list = NULL;
// 	t_list	*mapped;

// 	while(i < 3)
// 	{
// 		ft_lstadd_back(&list, ft_lstnew(&vals[i]));
// 		i++;
// 	}

// 	mapped = ft_lstmap(list, add_one, del);

// 	while (mapped)
// 	{
// 		printf("%d\n", *(int *)mapped->content);
// 		mapped = mapped->next;
// 	}
// }