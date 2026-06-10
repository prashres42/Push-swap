/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppourraj <ppourraj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 18:03:23 by ppourraj          #+#    #+#             */
/*   Updated: 2026/06/10 18:41:56 by ppourraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks		*data;
	t_flags			*flags;
	t_bench_status	*bench;
	
	data = NULL;
	flags = NULL;
	bench = NULL;
	if (argc < 2)
		return (0);
	if ((*argv)[0] == '-' && (*argv)[1] == '-')
		flags = check_flags(argv);
}
	
// initialize_var(&data, &flags, &bench);