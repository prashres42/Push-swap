/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 15:52:17 by prashres          #+#    #+#             */
/*   Updated: 2026/05/13 14:38:47 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset (s, '\0', n);
}

// int main(void)
// {
//     char str[] = "Hello, World!";
//     printf("Before: %s\n", str);
//     ft_bzero(str, 5);
//     printf("After (first 5 zeroed): %s\n", str + 5); 
//     return 0;
// }