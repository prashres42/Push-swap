/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppourraj <ppourraj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 15:12:52 by ppourraj          #+#    #+#             */
/*   Updated: 2026/06/10 17:46:06 by ppourraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void ra(t_stack **a)
{
    rotate(*a);
    write(1, "ra\n", 3);
}

void rb(t_stack **b)
{
    rotate(*b);
    write(1, "rb\n", 3);
}

void rr(t_stack **a, t_stack **b)
{
    rotate(*a);
    rotate(*b);
    write(1, "rr\n", 3);
}
