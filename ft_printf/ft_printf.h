/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 11:50:26 by prashres          #+#    #+#             */
/*   Updated: 2026/05/24 20:16:04 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

int	ft_print_char(char c);
int	ft_printstr(char *s);
int	ft_print_unsigned(unsigned int n);
int	ft_printnbr(long n);
int	ft_print_pointer(void *arg, char *base);
int	ft_print_hexa(unsigned long n, char *base);
int	ft_printf(const char *format, ...);

#endif