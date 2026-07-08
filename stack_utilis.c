/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppourraj <ppourraj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 15:39:06 by prashres          #+#    #+#             */
/*   Updated: 2026/07/08 14:13:33 by ppourraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_stack *stack)
{
	t_node *temp;
	
	if(!stack || stack->size < 2)
		return (1);
	temp = stack->top;
	while(temp->next)
	{
		if(temp->value > temp->next->value)
			return(0);
		temp = temp->next;
	}
	return (1);
}

t_stack	*new_stack(void)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->size = 0;
	new->top = NULL;
	return (new);
}

t_node *node_new(int value, t_stacks *data, t_ptr_b_f ptr)
{
	t_node *new;
	
	new = malloc(sizeof(t_node));
	if(!new)
		ft_error(data, ptr, NULL);
	new->value = value;
	new->index = 0;
	new->next = NULL;
	return(new);
}

void stack_addback(t_stack *stack, t_node *node)
{
	t_node *temp;
	
	if(!node)
		return;
	if(!stack->top)
	{
		stack->top = node;
		stack->size++;
		return;
	}
	temp = stack->top;
	while(temp->next)
		temp = temp->next;
	temp->next = node;
	stack->size++;
}
