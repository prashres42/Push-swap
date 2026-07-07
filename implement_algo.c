/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implement_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 15:22:56 by prashres          #+#    #+#             */
/*   Updated: 2026/07/07 15:16:27 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void implement_algo(t_stacks *data, t_flags *flags, t_bench *bench)
{
    t_flags *flag_value;
    int print;

    print = 0;
    if(flag_value->simple == 1)
        simple_selection(data, bench, print);
    else if(flag_value->medium == 1)
        medium_sort(data, bench, print);
    else if(flag_value->complex == 1)
        complex_radix(data, bench, print);
    else if(flag_value->adaptive == 1)
        adaptive_sort(data, bench, print);
}
void adaptive_sort(t_stacks *data, t_bench *bench, int print)
{
    if(bench->disorder < 0.2)
        simple_selection(data, bench, print);
    if(bench->disorder >= 0.2 || bench->disorder < 0.5)
        medium_sort(data, bench, print);
    if(bench->disorder >= 0.5)
        complex_radix(data, bench, print);        
}