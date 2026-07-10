/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 18:56:53 by prashres          #+#    #+#             */
/*   Updated: 2026/07/10 18:24:47 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bench	*ini_bench(void)
{
	t_bench	*bench;

	bench = malloc(sizeof(t_bench));
	if (!bench)
		return (NULL);
	bench->disorder = 0.0;
	bench->strategy = 0;
	bench->total_ops = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	return (bench);
}

t_ptr_b_f	bench_flags(t_bench *bench, t_flags *flags)
{
	t_ptr_b_f	ptr;

	ptr.bench = bench;
	ptr.flags = flags;
	return (ptr);
}
