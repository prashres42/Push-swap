/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_chunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppourraj <ppourraj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 11:32:24 by ppourraj          #+#    #+#             */
/*   Updated: 2026/06/26 15:38:08 by ppourraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int num)
{
	int i;

	i = 1;
	while (i * i < num)
		i++;
	return (i);
}

static void	chunk_sort(t_stacks *data, t_bench *bench, int print,
			int *chunk)
{
	int i;

	i = 0;
	while (data->a->size > 0)
	{
		if (data->a->top->index <= 1)
		{
			pb(data, bench, print);
			rb(data, bench, print);
			i++;
		}
		else if (data->a->top->index > i + *chunk)
		{
			pa(data, bench, print);
			i++;
		}
		else
		{
			ra(data, bench, print);
			i++;
		}
	}
	
}

void	sort_medium(t_stacks *data, t_bench *bench, int print)
{
	int	chunk;
	int	pos;

	chunk = ft_sqrt(data->a->size);
	sort_medium_helper(data, print, bench, &chunk);
	while (data->b->size > 0)
	{
		pos = find_max_pos(data->b);
		if (pos <= data->b->size / 2)
			while (pos-- > 0)
				rb(data, bench, print);
		else
			while (pos++ < data->b->size)
				rrb(data, bench, print);
		pa(data, print, bench);
	}
}