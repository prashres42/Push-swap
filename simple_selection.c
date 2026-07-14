/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_selection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppourraj <ppourraj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:28:00 by ppourraj          #+#    #+#             */
/*   Updated: 2026/07/13 20:15:39 by ppourraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_to_top(t_stacks *data, int pos, t_bench *bench, int print)
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

	bench->strategy = "Simple / O(n^2)";
	if (!data->a->top || !data->a->top->next)
		return ;
	if (data->a->size <= 5)
		return (sort_upto5(data, bench, print));
	while (!is_sorted(data->a))
	{
		pos = find_min_index(data->a);
		min_to_top(data, pos, bench, print);
		pb(data, bench, print);
	}
	while (data->b->size > 0)
		pa(data, bench, print);
}
