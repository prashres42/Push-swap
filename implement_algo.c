/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implement_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 15:22:56 by prashres          #+#    #+#             */
/*   Updated: 2026/07/09 18:45:38 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_stacks *data, t_bench *bench, int print)
{
	if (bench->disorder < 0.2)
		selection_sort(data, bench, print);
	else if (bench->disorder >= 0.2 || bench->disorder < 0.5)
		sort_medium(data, bench, print);
	else if (bench->disorder >= 0.5)
		radix_sort(data, bench, print);
}

void	implement_algo(t_stacks *data, t_bench *bench, t_flags *flag)
{
	int		print;

	print = 0;
	if (!flag)
		return ;
	if (flag->simple == 1)
		selection_sort(data, bench, print);
	else if (flag->medium == 1)
		sort_medium(data, bench, print);
	else if (flag->complex == 1)
		radix_sort(data, bench, print);
	else if (flag->adaptive == 1)
		adaptive_sort(data, bench, print);
}
