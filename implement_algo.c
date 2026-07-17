/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implement_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 15:22:56 by prashres          #+#    #+#             */
/*   Updated: 2026/07/17 12:50:10 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_stacks *data, t_bench *bench, int print)
{
	float	disorder;

	disorder = (float)bench->disorder / 10000;
	if (disorder < 0.2)
	{
		selection_sort(data, bench, print);
		bench->strategy = "Adaptive O(n^2)";
	}
	else if (disorder >= 0.2 && disorder < 0.5)
	{
		sort_medium(data, bench, print);
		bench->strategy = "Adaptive O(n√n)";
	}
	else
	{
		radix_sort(data, bench, print);
		bench->strategy = "Adaptive O(nlogn)";
	}
}

void	implement_algo(t_stacks *data, t_bench *bench, t_flags *flag)
{
	int	print;

	print = 1;
	if (flag && flag->bench)
		print = 0;
	if (!flag)
		adaptive_sort(data, bench, 1);
	else if (flag->simple == 1)
		selection_sort(data, bench, print);
	else if (flag->medium == 1)
		sort_medium(data, bench, print);
	else if (flag->complex == 1)
		radix_sort(data, bench, print);
	else if (flag->bench == 1)
		adaptive_sort(data, bench, print);
	else if (flag->adaptive == 1)
		adaptive_sort(data, bench, print);
}
