/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_upto5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppourraj <ppourraj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 18:17:26 by ppourraj          #+#    #+#             */
/*   Updated: 2026/07/14 17:08:14 by ppourraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stacks *data, t_bench *bench, int print)
{
	int	top;
	int	mid;
	int	bot;

	top = data->a->top->value;
	mid = data->a->top->next->value;
	bot = data->a->top->next->next->value;
	if (top > mid && mid < bot && top < bot)
		sa(data, bench, print);
	else if (top > mid && mid > bot)
	{
		sa(data, bench, print);
		rra(data, bench, print);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(data, bench, print);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(data, bench, print);
		ra(data, bench, print);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(data, bench, print);
}

static void	sort_four(t_stacks *data, t_bench *bench, int print)
{
	int	pos;

	pos = find_min_index(data->a);
	min_to_top(data, pos, bench, print);
	pb(data, bench, print);
	sort_three(data, bench, print);
	pa(data, bench, print);
}

static void	sort_five(t_stacks *data, t_bench *bench, int print)
{
	int	pos;

	pos = find_min_index(data->a);
	min_to_top(data, pos, bench, print);
	pb(data, bench, print);
	pos = find_min_index(data->a);
	min_to_top(data, pos, bench, print);
	pb(data, bench, print);
	sort_three(data, bench, print);
	pa(data, bench, print);
	pa(data, bench, print);
}

void	sort_upto5(t_stacks *data, t_bench *bench, int print)
{
	if (is_sorted(data->a))
		return ;
	if (data->a->size == 2)
		sa(data, bench, print);
	else if (data->a->size == 3)
		sort_three(data, bench, print);
	else if (data->a->size == 4)
		sort_four(data, bench, print);
	else if (data->a->size == 5)
		sort_five(data, bench, print);
	return ;
}
