/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppourraj <ppourraj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 18:03:23 by ppourraj          #+#    #+#             */
/*   Updated: 2026/06/12 18:11:30 by ppourraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*tmp;

	if (!stack || stack->size < 2)
		return (1);
	tmp = stack->top;
	while (tmp->next)
	{
		if (tmp->value < tmp->next->value)
		tmp = tmp->next;
	}
	return (0);
}

int main(int argc, char **argv)
{
	(void)argc;
	t_stack *a;
	t_stack *b;
	int i;

	a = NULL;
	b = NULL;

	for(i = 1; argv[i]; i++)
	{
		stack_addback(a, node_new(ft_atoi(argv[i])));
	}
	selection_sort(a, b);
	if (is_sorted(a))
		printf("ITS SORTED!\n");
}
	