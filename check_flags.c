/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppourraj <ppourraj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 10:57:18 by ppourraj          #+#    #+#             */
/*   Updated: 2026/07/08 17:10:42 by ppourraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static int	ft_strcmp(const char *s1, const  char *s2)
{
	while(*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static void handle_flags(t_flags *flags_values, char *argv)
{
	if (ft_strcmp(argv, "--simple") == 0)
		flags_values->simple += 1;
	else if (ft_strcmp(argv, "--medium") == 0)
		flags_values->medium += 1;
	else if (ft_strcmp(argv, "--complex") == 0)
		flags_values->complex += 1;
	else if (ft_strcmp(argv, "--adaptive") == 0)
		flags_values->adaptive += 1;
	else if (ft_strcmp(argv, "--bench") == 0)
		flags_values->bench += 1;
	else
	{
		ft_printf("Error\n");
		free(flags_values);
		exit(1);
	}
}

t_flags *check_flags(char **argv)
{
	t_flags *flags_values;

	flags_values = ft_calloc(1, sizeof(t_flags));
	if (!flags_values)
		return (NULL);
	while (*argv && ((*argv)[0] == '-' && (*argv)[1] == '-'))
		handle_flags(flags_values, *argv++);
	return (flags_values);
}
