/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 14:14:27 by prashres          #+#    #+#             */
/*   Updated: 2026/05/11 14:40:54 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
// #include <stdio.h>

// int main(void)
// {
//   // test 1 — basic allocation and zero initialization
// 	int i = 0;
//     int *arr = ft_calloc(5, sizeof(int));
//     if (!arr)
//         return (1);
//     printf("Test 1 - should all be 0:\n");
//    while (i < 5)
//    {
// 	   printf("arr[%d] = %d\n", i, arr[i]);
// 		i++;
//    }
//     free(arr);
// }