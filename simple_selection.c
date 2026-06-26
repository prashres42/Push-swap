/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_selection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppourraj <ppourraj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:26:58 by ppourraj          #+#    #+#             */
/*   Updated: 2026/06/26 12:46:40 by ppourraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void min_to_top(t_stacks *data, int pos, t_bench *bench)
{
	int moves;

	if (pos <= data->a->size / 2)
	{
		while (pos > 0)
		{
			ra(data, bench);
			pos--;
		}
	}
	else
	{
		moves = data->a->size - pos;
		while (moves > 0)
		{
			rra(data, bench);
			moves--;
		}
	}
}
void selection_sort(t_stacks *data, t_bench *bench)
{
	int pos;

	while (!is_sorted(data->a))
	{
		pos = find_min(data->a);
		min_to_top(data, pos, bench);
		pb(data, bench);
	}
	while (data->b->size > 0)
		pa(data, bench);
}
