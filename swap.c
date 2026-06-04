/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppourraj <ppourraj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 14:28:32 by ppourraj          #+#    #+#             */
/*   Updated: 2026/06/04 15:19:04 by ppourraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	temp;

	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
}

void sa(t_stack **a)
{
    swap(*a);
    write(1, "sa\n", 3);
}

void sb(t_stack **b)
{
    swap(*b);
    write(1, "sb\n", 3);
}

void ss(t_stack **a, t_stack **b)
{
    swap(*a);
    swap(*b);
    write(1, "ss\n", 3);
}

// testing swap function
/* int main(void)
{
	t_stack *first;
	t_stack *second;

	first = malloc(sizeof(t_stack));
	second = malloc(sizeof(t_stack));

	first->value = 10;
	first->next = second;

	second->value = 20;
	second->next = NULL;

	swap(first);
	printf("%d", first->value);
	free(first);
	free(second);
} */