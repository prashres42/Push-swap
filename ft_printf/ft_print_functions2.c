/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:23:43 by prashres          #+#    #+#             */
/*   Updated: 2026/05/24 20:12:39 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned long n, char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_print_hexa((n / 16), base);
	count += ft_print_char(base[n % 16]);
	return (count);
}

int	ft_print_pointer(void *arg, char *base)
{
	int	count;

	count = 0;
	if (!arg)
		return (ft_printstr("(nil)"));
	count += ft_printstr("0x");
	count += ft_print_hexa((unsigned long)arg, base);
	return (count);
}
