/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_radix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 15:02:37 by prashres          #+#    #+#             */
/*   Updated: 2026/07/07 15:44:47 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	max_index;
	int	max_bits;

	max_index = size - 1;
	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stacks *data, t_bench *bench, int print)
{
	int	max_bits;
	int	size;
	int	bit;
	int	i;

	bit = 0;
	size = data->a->size;
	max_bits = get_max_bits(size);
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((data->a->top->index >> bit) & 1) == 0)
				pb(data, bench, print);
			else
				ra(data, bench, print);
			i++;
		}
		while (data->b->size > 0)
			pa(data, bench, print);
		bit++;
	}
}
