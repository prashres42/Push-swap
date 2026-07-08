/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppourraj <ppourraj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 11:58:13 by ppourraj          #+#    #+#             */
/*   Updated: 2026/07/08 11:58:15 by ppourraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long ft_atol(const char *str)
{
	long result;
	int i ;
	int sign;

	sign = 1;
	result = 0;
	i = 0;
	if (!str || !*str)
		return (0);
	if(str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++; 
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		if (result > INT_MAX || result < INT_MIN)
			return (LONG_MAX);
		i++;
	}
	return (result * sign);
}

static char **split_check(char **splitted, char **argv, t_stacks *data, t_ptr_b_f ptr)
{
	splitted = ft_split(*argv, ' ');
	if(!splitted || !*splitted)
		ft_error(data, ptr, splitted);
	if(error_syntax(splitted))
		ft_error(data, ptr, splitted);
	return (splitted);
}

static int pars_args_helper(char **splitted, char **argv, t_stacks *data, t_ptr_b_f ptr)
{
	t_node *new;
	int i;
	long nbr;

	while(*argv)
	{
		i = 0;
		splitted = split_check(splitted, argv, data, ptr);
		argv++;
		while(splitted[i])
		{
			nbr = ft_atol(splitted[i]);
			if(nbr == LONG_MAX)
				ft_error(data, ptr, splitted);
			if(error_repitition(data->a->top, (int)nbr))
				ft_error(data, ptr, splitted);
			new = node_new(nbr, data, ptr);
			stack_addback(data->a, new);
			i++;
		}
		free_split(splitted);
	}
	return (0);
}

t_stacks *parse_args(char **argv, t_ptr_b_f ptr_b_f)
{
	t_stacks *data;
	char **splitted;
	
	splitted = NULL;
	data = malloc(sizeof(t_stacks));
	if(!data)
		return (NULL);
	data->a = new_stack();
	data->b = new_stack();
	if (!data->a || !data->b)
		return (ft_error(data, ptr_b_f, splitted), NULL);
	pars_args_helper(splitted, argv, data, ptr_b_f);
	return(data);
}
