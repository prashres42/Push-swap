/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 15:39:06 by prashres          #+#    #+#             */
/*   Updated: 2026/07/10 18:35:28 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*temp;

	if (!stack || stack->size < 2)
		return (1);
	temp = stack->top;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

t_stack	*new_stack(void)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->size = 0;
	new->top = NULL;
	return (new);
}

t_node	*node_new(int value, t_stacks *data, t_ptr_b_f ptr)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		ft_error(data, ptr, NULL);
	new->value = value;
	new->index = 0;
	new->next = NULL;
	return (new);
}

void	stack_addback(t_stack *stack, t_node *node)
{
	t_node	*temp;

	if (!node)
		return ;
	if (!stack->top)
	{
		stack->top = node;
		stack->size++;
		return ;
	}
	temp = stack->top;
	while (temp->next)
		temp = temp->next;
	temp->next = node;
	stack->size++;
}

void	print_bench(t_bench *bench)
{
	if (!bench)
		return ;
	ft_printf("[bench] disorder: %i.%i",
		bench->disorder / 100, bench->disorder % 100);
	ft_print_char('%');
	ft_printf("\n");
	ft_printf("[bench] strategy: %s\n", bench->strategy);
	ft_printf("[bench] total_ops: %d\n", bench->total_ops);
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", bench->sa, \
bench->sb, bench->ss, bench->pa, bench->pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr %d\n", \
bench->ra, bench->rb, bench->rr, bench->rra, bench->rrb, bench->rrr);
}
