/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 19:08:13 by prashres          #+#    #+#             */
/*   Updated: 2026/05/11 14:34:29 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (0);
	i = 1;
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
// int main()
// {
// 	t_list *test_null = NULL;
// 	printf("nbr nodes = %i\n", ft_lstsize(test_null));
// 	t_list node;
// 	t_list node1;
// 	t_list node2;
// 	node.content = "hello";
// 	node.next = &node1;

// 	node1.content = "smegol";
// 	node1.next = &node2;

// 	node2.content = "ffff";
// 	node2.next = NULL;
// 	printf("nbr nodes = %i\n", ft_lstsize(&node));

// 	return (0);
// }