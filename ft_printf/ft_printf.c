/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 13:48:35 by prashres          #+#    #+#             */
/*   Updated: 2026/05/26 11:51:08 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(char specifier, va_list arg)
{
	char	*small;
	char	*big;
	int		count;

	count = 0;
	small = "0123456789abcdef";
	big = "0123456789ABCDEF";
	if (specifier == 'c')
		count += ft_print_char(va_arg(arg, int));
	else if (specifier == 's')
		count += ft_printstr(va_arg(arg, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_printnbr(va_arg(arg, int));
	else if (specifier == 'p')
		count += ft_print_pointer(va_arg(arg, void *), small);
	else if (specifier == 'u')
		count += ft_print_unsigned(va_arg(arg, unsigned int));
	else if (specifier == 'x')
		count += ft_print_hexa(va_arg(arg, unsigned int), small);
	else if (specifier == 'X')
		count += ft_print_hexa(va_arg(arg, unsigned int), big);
	else if (specifier == '%')
		count += ft_print_char('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		count;
	int		i;

	count = 0;
	if (!format)
		return (-1);
	va_start(arg, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			count += print_format(format[++i], arg);
		else
			count += ft_print_char(format[i]);
		i++;
	}
	va_end(arg);
	return (count);
}

// int	main(void)
// {
// 	char			*z;
// 	char			*y;
// 	int				a;
// 	char			str[] = "Strangers in the night - Frank Sinatra";
// 	int				*ptr;
// 	int				**test;
// 	int				dec;
// 	int				ndec;
// 	unsigned int	ciao;
// 	unsigned int	ben10;
// 	int				ohyeah;

// 	printf("\n\n\n-------------TESTING EDGE CASES-------------\n\n\n");
// 	z = "ola bom dia %K%s %% %i %d %X %u\0";
// 	printf("a''''%d''''\n",      printf(z, "a todos", NULL, NULL, 2147483647,
// 			-2147483648, -32, -12334567, -1, "ola bom dia a todos"));
// 	ft_printf("\n");
// 	ft_printf("a''''%d''''\n",ft_printf(z, "a todos", NULL, NULL, 2147483647,
// 			-2147483648, -32, -12334567, -1, "ola bom dia a todos"));
// 	printf("\n\n\n");
// 	y = "ola bom dia %K%s %% %s %i %X %u\0";
// 	printf("a''''%d''''\n",      printf(y, "a todos", NULL, NULL, NULL, NULL,
// 			NULL, NULL, NULL, NULL));
// 	ft_printf("\n");
// 	ft_printf("a''''%d''''\n",ft_printf(y, "a todos", NULL, NULL, NULL, NULL,
// 			NULL, NULL, NULL, NULL));
// 	printf("\n\n\n");
// 	printf("Some test\n");
// 	printf("%d %d\n", printf("%c ", 'a'), ft_printf("%c ", 'a'));
// 	printf("\n\n\n");
// 	// teste ale
// 	printf("\nTeste do ale\n");
// 	printf("My own: %i\n", ft_printf(NULL));
// 	printf("Original: %i\n", printf(NULL));
// 	printf("\n\n\n");
// 	// Printando characters: %c
// 	a = 0;
// 	printf("Lidando com %%c\n");
// 	printf("Original: %c\n", 98);
// 	printf("Original: %c\n", a);
// 	printf("Original: %c\n", a + 73);
// 	printf("Original: %c\n", 200);
// 	printf("Original: %c\n\n", -200);
// 	ft_printf("My Own: %c\n", 98);
// 	ft_printf("My Own: %c\n", a);
// 	ft_printf("My Own: %c\n", a + 73);
// 	ft_printf("My Own: %c\n", 200);
// 	ft_printf("My own: %c\n\n", -200);
// 	// Printando characters: %s
// 	printf("Lidando com %%s\n");
// 	printf("Original: %s\n", str);
// 	printf("Original: %s\n", str + 5);
// 	printf("Original: %s\n\n", "mt \200 friends this is weir-\0");
// 	//
// 	ft_printf("My own: %s\n", str);
// 	ft_printf("My own: %s\n", str + 5);
// 	ft_printf("My own: %s\n\n", "mt \200 friends this is weir-\0");
// 	// Printando characters: %p
// 	ptr = &a;
// 	test = &ptr;
// 	printf("Lidando com %%p\n");
// 	printf("Original: %p\n", ptr);
// 	printf("Original: %p\n", &a);
// 	printf("Original: %p\n", ptr + a);
// 	printf("Original: %p\n", &ptr + 446546);
// 	printf("Original: %p\n\n", &test);
// 	printf("Lidando com %%p\n");
// 	ft_printf("My own: %p\n", ptr);
// 	ft_printf("My own: %p\n", &a);
// 	ft_printf("My own: %p\n", ptr + a);
// 	ft_printf("My own: %p\n", &ptr + 446546);
// 	ft_printf("My own: %p\n\n", &test);
// 	// Printando characters: %d
// 	dec = 2147483644;
// 	ndec = -2147483644;
// 	printf("Lidando com %%d\n");
// 	printf("Original: %d\n", dec);
// 	printf("Original: %d\n", dec - 2);
// 	printf("Original: %d\n", ndec);
// 	printf("Original: %d\n", ndec + 2 - (ndec / 2));
// 	printf("Original: %d\n\n", dec + ndec);
// 	ft_printf("My own: %d\n", dec);
// 	ft_printf("My own: %d\n", dec - 2);
// 	ft_printf("My own: %d\n", ndec);
// 	ft_printf("My own: %d\n", ndec + 2 - (ndec / 2));
// 	ft_printf("My own: %d\n\n", dec + ndec);
// 	// Printando characters: %i
// 	printf("Lidando com %%i\n");
// 	printf("Original: %i\n", dec);
// 	printf("Original: %i\n", dec - 2);
// 	printf("Original: %i\n", ndec);
// 	printf("Original: %i\n", ndec + 2 - (ndec / 2));
// 	printf("Original: %i\n\n", dec + ndec);
// 	ft_printf("My own: %i\n", dec);
// 	ft_printf("My own: %i\n", dec - 2);
// 	ft_printf("My own: %i\n", ndec);
// 	ft_printf("My own: %i\n", ndec + 2 - (ndec / 2));
// 	ft_printf("My own: %i\n\n", dec + ndec);
// 	// Printando characters: %u
// 	ciao = 47688;
// 	printf("Lidando com %%u\n");
// 	printf("Original: %u\n", ciao);
// 	printf("Original: %u\n", 0 - 2);
// 	printf("Original: %u\n", -7);
// 	printf("Original: %u\n\n", ciao + 2 - (ndec / 2));
// 	ft_printf("My own: %u\n", ciao);
// 	ft_printf("My own: %u\n", 0 - 2);
// 	ft_printf("My own: %u\n", -7);
// 	ft_printf("My own: %u\n\n", ciao + 2 - (ndec / 2));
// 	// Printando characters: %x
// 	ben10 = -1000;
// 	ohyeah = 1000;
// 	printf("Lidando com %%x\n");
// 	printf("Original: %x\n", ben10);
// 	printf("Original: %x\n", ohyeah);
// 	printf("Original: %x\n", ben10 + 10 * 2);
// 	printf("Original: %x\n", 'a');
// 	printf("Original: %x\n\n", 14 / 2 * (12 / 7));
// 	ft_printf("My own %x\n", ben10);
// 	ft_printf("My own %x\n", ohyeah);
// 	ft_printf("My own %x\n", ben10 + 10 * 2);
// 	ft_printf("My own %x\n", 'a');
// 	ft_printf("My own %x\n\n", 14 / 2 * (12 / 7));
// 	// Printando characters: %X
// 	printf("Lidando com %%X\n");
// 	printf("Original: %X\n", ben10);
// 	printf("Original: %X\n", ohyeah);
// 	printf("Original: %X\n", ben10 + 10 * 2);
// 	printf("Original: %X\n", 'a');
// 	printf("Original: %X\n\n", 14 / 2 * (12 / 7));
// 	ft_printf("My own %X\n", ben10);
// 	ft_printf("My own %X\n", ohyeah);
// 	ft_printf("My own %X\n", ben10 + 10 * 2);
// 	ft_printf("My own %X\n", 'a');
// 	ft_printf("My own %X\n\n", 14 / 2 * (12 / 7));
// }