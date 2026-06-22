/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppourraj <ppourraj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 20:01:15 by ppourraj          #+#    #+#             */
/*   Updated: 2026/06/22 20:01:22 by ppourraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int error_syntax(char **a)
{
	int i;
	int j;

	i = 0;
	j = 0; 
	while(a[i])
	{
		while(a[i][j])
		{
			if(!ft_isdigit(a[i][j]))
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	error_repitition(t_node *a, int nbr)
{
	if(a == NULL)
		return (0);
	while(a)
	{
		if(a->value == nbr)
			return(1);
		a = a->next;
	}
	return (0);
}
void ft_error(t_stacks *data, t_ptr_b_f ptr, char **splitted)
{
	if(splitted)
		free_split(splitted);
	free_data (data, ptr.bench, ptr.flags);
	write (2, "Error\n", 7);
	exit(1);
}
void free_data(t_stacks *data, t_bench *bench, t_flags *flags)
{
	if(!data)
		return;
	if(flags)
		free(flags);
	if(bench)
		free(bench);
	if(data->a)
		stack_free(data->a);
	if(data->b)
		stack_free(data->b);
	free(data);
}
void free_split(char **splitted)
{
	int i;

	i = 0;
	while(splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}
void stack_free(t_stack *stack)
{
	t_node *temp;
	if(!stack)
		return;
	while(stack->top)
	{
		temp = stack->top;
		stack->top = stack->top->next;
		free(temp);
	}
	free(stack);
}
void free_memory(t_bench *bench, t_flags *flag)
{
	free(flag);
	free(bench);
}
