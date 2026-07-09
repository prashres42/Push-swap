/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilis2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppourraj <ppourraj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 14:13:19 by ppourraj          #+#    #+#             */
/*   Updated: 2026/07/08 17:02:37 by ppourraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_min_index(t_stack *stack)
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

int find_max_index(t_stack *stack)
{
	t_node *current;
	int i;
	int max_index;
	int max_value;

	if (!stack || stack->size == 0)
		return (-1);
	i = 0;
	max_index = 0;
	current = stack->top;
	max_value = current->value;
	while (current)
	{
		if (current->value > max_value)
		{
			max_value = current->value;
			max_index = i;
		}
		current = current->next;
		i++;
	}
	return (max_index);
}

void  assign_indexes(t_stacks *data)
{
    t_node  *i;
    t_node  *j;
    int rank;

    i = data->a->top;
    while (i)
    {
        rank = 0;
        j = data->a->top;
        while (j)
        {
            if (j->value < i->value)
                rank++;
            j = j->next;
        }
        i->index = rank;
        i = i->next;
    }
}

void print_stack(t_stack *stack)
{
    t_node *current;

    current = stack->top;
    while(current)
    {
        printf("%d", current->value);
        current = current->next;
    }
    printf("\n");
}
