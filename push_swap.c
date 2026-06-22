/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppourraj <ppourraj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 20:03:33 by ppourraj          #+#    #+#             */
/*   Updated: 2026/06/22 20:03:45 by ppourraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ini_var(t_stacks **data, t_flags **flags, t_bench **bench)
{
	*data = NULL;
	*flags = NULL;
	*bench = NULL;
}

int main(int argc, char **argv)
{
	t_stacks *data;
	t_flags *flags;
	t_bench *bench;
	int a = 0;

	if (argc < 2)
		return (0);
	printf("hello\n");
	ini_var(&data, &flags, &bench);
	argv++;
	if((*argv)[0] == '-' && (*argv)[1] == '-')
		flags = check_flags(argv);
	printf("hello2\n");
	argv += flags_total(flags);
	printf("hello");
	bench = ini_bench();
	printf("hello3\n");
	if(*argv)
		data = parse_args(argv, bench_flags(bench, flags));
	printf("hello4\n");
		if(!data)
		return(free_memory(bench,flags),1);
	if(is_sorted(data->a))
		return(free_memory(bench,flags),0);
	a = bench->disorder= (int)(compute_disorder(data->a) * 10000);
	// algorithms(data, bench, flags);	
	printf("%d", a);
	printf("hello5\n");
}
