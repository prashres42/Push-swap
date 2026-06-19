/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppourraj <ppourraj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 15:19:25 by ppourraj          #+#    #+#             */
/*   Updated: 2026/06/04 15:24:10 by ppourraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void rra(t_stack **a)
{
    reverse_rotate(*a);
    write(1, "rra\n", 4);
}

void rrb(t_stack **b)
{
    reverse_rotate(*b);
    write(1, "rrb\n", 4);
}

void rrr(t_stack **a, t_stack **b)
{
    reverse_rotate(*a);
    reverse_rotate(*b);
    write(1, "rrr\n", 4);
}
