/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 15:19:25 by ppourraj          #+#    #+#             */
/*   Updated: 2026/07/16 12:09:46 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	t_node	*pre_top;
	t_node	*pre_bottom;
	t_node	*new_bottom;

	if (!stack || stack->size < 2)
		return ;
	pre_top = stack->top;
	pre_bottom = stack->top;
	new_bottom = stack->top;
	while (pre_bottom->next)
		pre_bottom = pre_bottom->next;
	while (new_bottom->next->next)
		new_bottom = new_bottom->next;
	stack->top = pre_bottom;
	pre_bottom->next = pre_top;
	new_bottom->next = NULL;
}

void	rra(t_stacks *data, t_bench *bench, int print)
{
	reverse_rotate(data->a);
	bench->total_ops++;
	bench->rra++;
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stacks *data, t_bench *bench, int print)
{
	reverse_rotate(data->b);
	bench->total_ops++;
	bench->rrb++;
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stacks *data, t_bench *bench, int print)
{
	reverse_rotate(data->a);
	reverse_rotate(data->b);
	bench->total_ops++;
	bench->rrr++;
	if (print)
		write(1, "rrr\n", 4);
}
