/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 18:07:06 by prashres          #+#    #+#             */
/*   Updated: 2026/05/11 14:19:45 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < (size - 1) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen (src));
}
// int main(void)
// {
//     char    *str1 = "Hello";
//     char    str2[3];
//     size_t  i;
//     i = ft_strlcpy(str2, str1, 3);
//     printf("Copied is: %s and source len is: %zu\n", str2, i);
//     return (0);
// }