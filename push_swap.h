/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppourraj <ppourraj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 18:03:46 by ppourraj          #+#    #+#             */
/*   Updated: 2026/06/01 18:03:49 by ppourraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "printf.h"

# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}				t_stack;

#endif
