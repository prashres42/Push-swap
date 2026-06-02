/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 13:59:15 by prashres          #+#    #+#             */
/*   Updated: 2026/05/11 14:28:56 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char )c;
		i++;
	}
	return ((unsigned char *)s);
}

// int main()
// {
//     char buffer[5];
//     ft_memset(buffer, 'A', 5);
//     printf("%s\n", buffer);
//     memset(buffer, 'B', 5);
//     printf("%s\n", buffer);
// }
