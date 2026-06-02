/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 11:43:54 by prashres          #+#    #+#             */
/*   Updated: 2026/05/15 12:33:31 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*a;
	const unsigned char	*b;

	if (!dest && !src)
		return (NULL);
	i = 0;
	a = (unsigned char *)dest;
	b = (const unsigned char *)src;
	while (i < n)
	{
		a[i] = b[i];
		i++;
	}
	return (dest);
}
// #include <stdio.h>
// int main()
// {
// 	const char *src = "this is a page";
// 	char dest[20] = "page s";
// 	size_t n = 6;
// 	ft_memcpy(dest, src, n);
// 	printf("%s", dest); 
// }
// int main()
// {
// 	 const char *src = "hello world";
// 	 char buf[10] = "unchanged";
//     ft_memcpy(buf, src, 0);
//     printf("n=0:      %s\n", buf); // "unchanged"

//     return 0;
// }