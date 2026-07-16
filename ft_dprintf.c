/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 14:56:55 by prashres          #+#    #+#             */
/*   Updated: 2026/07/16 15:50:29 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	putnbr_fd(int n, int fd)
{
	long	nb;
	int		len;
	char	c;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		write(fd, "-", 1);
		len++;
		nb = -nb;
	}
	if (nb >= 10)
		len += putnbr_fd(nb / 10, fd);
	c = (nb % 10) + '0';
	write(fd, &c, 1);
	return (len + 1);
}

static int	putstr_fd(char *s, int fd)
{
	int	len;

	if (!s)
		s = "(null)";
	len = 0;
	while (s[len])
	{
		write(fd, &s[len], 1);
		len++;
	}
	return (len);
}

static int	handle_format(va_list args, char c, int fd)
{
	if (c == 'd' || c == 'i')
		return (putnbr_fd(va_arg(args, int), fd));
	else if (c == 's')
		return (putstr_fd(va_arg(args, char *), fd));
	else if (c == '%')
		return (write(fd, "%", 1));
	return (0);
}

int	ft_dprintf(int fd, const char *fmt, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, fmt);
	i = 0;
	count = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1])
		{
			count += handle_format(args, fmt[i + 1], fd);
			i += 2;
		}
		else
		{
			write(fd, &fmt[i], 1);
			count++;
			i++;
		}
	}
	va_end(args);
	return (count);
}
