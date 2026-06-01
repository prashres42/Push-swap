/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppourraj <ppourraj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 10:44:12 by ppourraj          #+#    #+#             */
/*   Updated: 2026/06/01 18:05:36 by ppourraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	temp;

	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
}

static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*top;

	// if src is empty we cant push anything
	if (!src)
		return ;
	top = *src;
	*src = (*src)->next;
	top->next = *dest;
	*dest = top;
}

static void	rotate(t_stack **top)
{
	t_stack	*pre_top;
	t_stack	*bottom;

	pre_top = *top;
	*top = (*top)->next;
	bottom = *top;
	while (bottom->next)
		bottom = bottom->next;
	pre_top->next = NULL;
	bottom->next = pre_top;
}

static void	reverse_rotate(t_stack **top)
{
	t_stack	*pre_top;
	t_stack	*pre_bottom;
	t_stack	*new_bottom;

	pre_top = *top;
	pre_bottom = *top;
	new_bottom = *top;
	while (pre_bottom->next)
		pre_bottom = pre_bottom->next;
	while (new_bottom->next->next)
		new_bottom = new_bottom->next;
	*top = pre_bottom;
	pre_bottom->next = pre_top;
	new_bottom->next = NULL;
}

// testing swap function
/* int main(void)
{
	t_stack *first;
	t_stack *second;

	first = malloc(sizeof(t_stack));
	second = malloc(sizeof(t_stack));

	first->value = 10;
	first->next = second;

	second->value = 20;
	second->next = NULL;

	swap(first);
	printf("%d", first->value);
	free(first);
	free(second);
} */
