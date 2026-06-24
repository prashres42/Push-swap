/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_chunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppourraj <ppourraj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 11:32:24 by ppourraj          #+#    #+#             */
/*   Updated: 2026/06/24 19:00:47 by ppourraj         ###   ########.fr       */
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

static void	chunk_sort(t_stacks *data, t_bench *bench, int *chunk)
{
	int i;

	i = 0;
	while (data->a->size > 0)
	{
		if (data->a->top->index <= 1)
		{
			pb(data, bench);
			rb(data, bench);
			i++;
		}
		else if (data->a->top->index > i + *chunk)
		{
			pa(data, bench);
			i++;
		}
		else
		{
			ra(data, bench);
			i++;
		}
	}
	
}

void medium_sort(t_stacks *data, int print, t_bench *bench)
{
    int chunk;
    
    chunk = ft_sqrt(data->a->size);
    chunk_sort(data, bench, chunk);
}