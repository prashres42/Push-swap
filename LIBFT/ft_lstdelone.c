/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 11:42:58 by prashres          #+#    #+#             */
/*   Updated: 2026/05/15 11:43:01 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del (lst->content);
	free (lst);
}

// void outrafuncao(void *content)
// {
// 	free(content);
// }

// int main()
// {
// 	t_list *node;

// 	printf("%p\n", node);

// 	// node = malloc(sizeof(t_list));

// 	// node->content = malloc(sizeof(int));

// 	// ft_lstdelone(node, outrafuncao);

// 	return 0;
// }
