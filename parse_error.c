/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 15:19:38 by prashres          #+#    #+#             */
/*   Updated: 2026/06/26 15:19:39 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int error_syntax(char **a)
{
	int i;
	int j;

	i = 0;
	j = 0; 
	while(a[i])
	{
		j = 0;
		if (a[i][j] == '-' || a[i][j] == '+')
        	j++;
		while(a[i][j])
		{
			if(!ft_isdigit(a[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	error_repitition(t_node *a, int nbr)
{
	if(a == NULL)
		return (0);
	while(a)
	{
		if(a->value == nbr)
			return(1);
		a = a->next;
	}
	return (0);
}