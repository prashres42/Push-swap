/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 14:28:32 by ppourraj          #+#    #+#             */
/*   Updated: 2026/07/16 12:18:38 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	temp;

	if (!stack || stack->size < 2)
		return ;
	temp = stack->top->value;
	stack->top->value = stack->top->next->value;
	stack->top->next->value = temp;
}

void	sa(t_stacks *data, t_bench *bench, int print)
{
	swap(data->a);
	bench->total_ops++;
	bench->sa++;
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stacks *data, t_bench *bench, int print)
{
	swap(data->b);
	bench->total_ops++;
	bench->sb++;
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stacks *data, t_bench *bench, int print)
{
	swap(data->a);
	swap(data->b);
	bench->total_ops++;
	bench->ss++;
	if (print)
		write(1, "ss\n", 3);
}
