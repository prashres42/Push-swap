/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 12:32:03 by prashres          #+#    #+#             */
/*   Updated: 2026/07/10 18:25:19 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ini_var(t_stacks **data, t_flags **flags, t_bench **bench)
{
	*data = NULL;
	*flags = NULL;
	*bench = NULL;
}

int	main(int argc, char **argv)
{
	t_stacks	*data;
	t_flags		*flags;
	t_bench		*bench;

	if (argc < 2)
		return (0);
	ini_var(&data, &flags, &bench);
	argv++;
	if ((*argv)[0] == '-' && (*argv)[1] == '-')
		flags = check_flags(argv);
	argv += flags_total(flags);
	bench = ini_bench();
	if (*argv)
		data = parse_args(argv, bench_flags(bench, flags));
	if (!data)
		return (free_memory(bench, flags), 1);
	if (is_sorted(data->a))
		return (free_memory(bench, flags), 0);
	bench->disorder = (int)(compute_disorder(data->a) * 10000);
	assign_indexes(data);
	implement_algo(data, bench, flags);
	if (flags && flags->bench)
		print_bench(bench);
	free_data(data, bench, flags);
	return (0);
}
