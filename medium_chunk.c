/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_chunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppourraj <ppourraj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 11:32:24 by ppourraj          #+#    #+#             */
/*   Updated: 2026/06/22 17:54:01 by ppourraj         ###   ########.fr       */
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

static void	chunk_sort(t_stacks *data, int print, t_bench_status *bench,
			int *chunk)
{
	int i;

	i = 0;
	while (data->a->size > 0)
	{
		if (data->a->top->index <= 1)
		{
			pb()
		}
	}
	
}