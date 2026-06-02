/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:34:20 by prashres          #+#    #+#             */
/*   Updated: 2026/05/11 14:17:03 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && (s1[i] == s2[i]))
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
// int main()
// {
// 	const char s1[] = "hflo";
// 	const char s2[] = "hglo";
// 	size_t i = 3;
// 	printf ("%zu\n", ft_strncmp (s1, s2 , i));
// 	printf ("%zu\n", strncmp (s1, s2, i));
// }