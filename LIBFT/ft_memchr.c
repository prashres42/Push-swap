/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 13:21:55 by prashres          #+#    #+#             */
/*   Updated: 2026/05/13 15:28:53 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*a;

	i = 0;
	a = (const unsigned char *)s;
	while (i < n)
	{
		if (a[i] == (unsigned char )c)
			return ((void *)&a[i]);
		i++;
	}
	return (NULL);
}
// int main()
// {
// 	char str[] = "hello world";	
// 	char *found = ft_memchr(str, 'o', 11);
// 	printf("%s\n", found);  // "o world"
// }