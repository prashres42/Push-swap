/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppourraj <ppourraj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 14:55:23 by ppourraj          #+#    #+#             */
/*   Updated: 2026/07/09 19:46:27 by ppourraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *src, t_stack *dest)
{
	t_node	*first;

	if (!src || src->size == 0)
		return ;
	first = src->top;
	src->top = first->next;
	first->next = dest->top;
	dest->top = first;
	src->size--;
	dest->size++;
}

void	pa(t_stacks *data, t_bench *bench, int print)
{
	push(data->b, data->a);
	bench->total_ops++;
	bench->pa++;
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stacks *data, t_bench *bench, int print)
{
	push(data->a, data->b);
	bench->total_ops++;
	bench->pb++;
	if (print)
		write(1, "pb\n", 3);
}
