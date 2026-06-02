/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 19:21:51 by prashres          #+#    #+#             */
/*   Updated: 2026/05/11 14:35:45 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
// #include <stdio.h>
// int main()
// {
// 	t_list *last;
// 	t_list *head = ft_lstnew("0");
// 	t_list *node1 = ft_lstnew("1");
// 	t_list *node2 = ft_lstnew("2");
// 	t_list *node3 = ft_lstnew("3");
// 	head->next = node1;
// 	node1->next = node2;
// 	node2->next = node3;
// 	last = ft_lstlast(head);
// 	printf("content = %p\n", last);
// 	printf("content = %p\n", node3);
// 	return 0;
// }