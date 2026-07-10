/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 15:12:52 by ppourraj          #+#    #+#             */
/*   Updated: 2026/07/10 15:03:40 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	t_node	*pre_top;
	t_node	*bottom;

	if (!stack || stack->size < 2)
		return ;
	pre_top = stack->top;
	stack->top = stack->top->next;
	bottom = stack->top;
	while (bottom->next)
		bottom = bottom->next;
	pre_top->next = NULL;
	bottom->next = pre_top;
}

void	ra(t_stacks *data, t_bench *bench, int print)
{
	rotate(data->a);
	bench->total_ops++;
	bench->ra++;
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stacks *data, t_bench *bench, int print)
{
	rotate(data->b);
	bench->total_ops++;
	bench->rb++;
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stacks *data, t_bench *bench, int print)
{
	rotate(data->a);
	rotate(data->b);
	bench->total_ops++;
	bench->rr++;
	if (print)
		write(1, "rr\n", 3);
}
