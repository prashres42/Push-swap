/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_selection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:26:58 by ppourraj          #+#    #+#             */
/*   Updated: 2026/07/10 18:28:53 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_to_top(t_stacks *data, int pos, t_bench *bench, int print)
{
	int	moves;

	if (pos <= data->a->size / 2)
	{
		while (pos > 0)
		{
			ra(data, bench, print);
			pos--;
		}
	}
	else
	{
		moves = data->a->size - pos;
		while (moves > 0)
		{
			rra(data, bench, print);
			moves--;
		}
	}
}

int	find_min_index(t_stack *stack)
{
	t_node	*current;
	int		i;
	int		min_index;
	int		min_value;

	if (!stack || stack->size == 0)
		return (-1);
	i = 0;
	min_index = 0;
	current = stack->top;
	min_value = current->value;
	while (current)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_index = i;
		}
		current = current->next;
		i++;
	}
	return (min_index);
}

void	selection_sort(t_stacks *data, t_bench *bench, int print)
{
	int	pos;

	bench->strategy = "Simple / O(n^2)";
	if (!data->a->top || !data->a->top->next)
		return ;
	while (!is_sorted(data->a))
	{
		pos = find_min_index(data->a);
		min_to_top(data, pos, bench, print);
		pb(data, bench, print);
	}
	while (data->b->size > 0)
		pa(data, bench, print);
}
