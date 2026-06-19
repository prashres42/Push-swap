/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppourraj <ppourraj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 14:55:23 by ppourraj          #+#    #+#             */
/*   Updated: 2026/06/10 17:44:26 by ppourraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*top;

	if (!src)
		return ;
	top = *src;
	*src = (*src)->next;
	top->next = *dest;
	*dest = top;
}

void pa(t_stack **a, t_stack **b)
{
    push(a, b);
    write(1, "pa\n", 3);
}

void pb(t_stack **a, t_stack **b)
{
    push(b, a);
    write(1, "pb\n", 3);
}
