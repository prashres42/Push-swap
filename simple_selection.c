/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_selection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppourraj <ppourraj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:26:58 by ppourraj          #+#    #+#             */
/*   Updated: 2026/06/24 18:03:44 by ppourraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_stack *a)
{
	int top;
	int mid;
	int bot;

	top = a->top->value;
	mid = a->top->next->value;
	bot = a->top->next->next->value;
	if (top > mid && mid < bot && top < bot)
        sa();
    else if (top > mid && mid > bot)
	{
        sa(a);
		rra(a);
	}
    else if (top > mid && mid < bot && top > bot)
        ra(a);
    else if (top < mid && mid > bot && top < bot)
	{
        sa(a);
		ra(a); 
	}
    else if (top < mid && mid > bot && top > bot)
        rra(a);
}

int find_min(t_stack *s)
{
	t_node	*current;
	int		i;
	int		min_index;
	int		min_value;

	i = 0;
	min_index = 0;
	current = s->top;
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
void min_to_top(t_stack *a)
{
	int min_index;
	int moves;
	
	min_index = find_min(a);
	if (min_index <= a->size / 2)
	{
		while (min_index > 0)
		{
			ra(a);
			min_index--;
		}
	}
	else
	{
		moves = a->size - min_index;
		while (moves > 0)
		{
			rra(a);
			moves--;
		}
	}
}
void selection_sort(t_stacks *data, t_bench *bench)
{
	
	while (data->a->size > 3)
	{
		min_to_top(data->a);
		pb(data->a, data->b);
	}
	sort_three(data->a);
	while (data->b->top != NULL)
		pa(data->b, data->a);
}
