/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:43:40 by prashres          #+#    #+#             */
/*   Updated: 2026/05/24 20:12:07 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	return (write (1, &c, 1));
}

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_printnbr(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		ft_print_char('-');
		n = -n;
		count++;
	}
	if (n >= 10)
		count += ft_printnbr(n / 10);
	count += ft_print_char((n % 10) + '0');
	return (count);
}

int	ft_print_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_print_unsigned(n / 10);
	count += ft_print_char((n % 10) + '0');
	return (count);
}

// int main()
// {
// 	char c = 97;
// 	printf("%c\n", c);
// 	ft_printc(c);
// }