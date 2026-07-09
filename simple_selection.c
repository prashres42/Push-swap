/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_selection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppourraj <ppourraj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:26:58 by ppourraj          #+#    #+#             */
/*   Updated: 2026/07/08 12:01:55 by ppourraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	min_to_top(t_stacks *data, int pos, t_bench *bench, int print)
{
	int	moves;

	if (pos <= data->a->size / 2)
	{
		while (pos > 0)
		{
			ra(data, bench, print);
			pos--;
		}
	}
	else
	{
		moves = data->a->size - pos;
		while (moves > 0)
		{
			rra(data, bench, print);
			moves--;
		}
	}
}

void	selection_sort(t_stacks *data, t_bench *bench, int print)
{
	int	pos;

	while (!is_sorted(data->a))
	{
		pos = find_min_index(data->a);
		min_to_top(data, pos, bench, print);
		pb(data, bench);
	}
	while (data->b->size > 0)
		pa(data, bench);
}
