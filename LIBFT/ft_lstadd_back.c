/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 11:42:30 by prashres          #+#    #+#             */
/*   Updated: 2026/05/15 11:42:45 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast (*lst);
	temp->next = new;
}
// void print(t_list *lst)
// {
// 	while(lst)
// 	{
// 		printf("%s -> ", (char*)lst->content);
// 		lst = lst->next;
// 	}
// 	printf("NULL\n");
// }
// int main()
// {
// 	t_list *new;
// 	ft_lstadd_back(&new, ft_lstnew("first"));
// 	print(new);

// 	ft_lstadd_back(&new, ft_lstnew("second"));
// 	print(new);
// }
