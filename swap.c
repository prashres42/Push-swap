/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppourraj <ppourraj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 14:28:32 by ppourraj          #+#    #+#             */
/*   Updated: 2026/06/24 16:55:03 by ppourraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	temp;
    
    if(!stack || stack->size < 2)
		return ;
	temp = stack->top->value;
	stack->top->value = stack->top->next->value;
	stack->top->next->value = temp;
}

void sa(t_stacks *data, t_bench *bench)
{
    swap(data->a);
	bench->total_ops++;
	bench->sa++;
    write(1, "sa\n", 3);
}

void sb(t_stacks *data, t_bench *bench)
{
    swap(data->b);
	bench->total_ops++;
	bench->sb++;
    write(1, "sb\n", 3);
}

void ss(t_stacks *data, t_bench *bench)
{
    swap(data->a);
    swap(data->b);
	bench->total_ops++;
	bench->ss++;
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