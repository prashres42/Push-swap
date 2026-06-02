/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 10:49:47 by prashres          #+#    #+#             */
/*   Updated: 2026/05/13 14:15:20 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	lil_len;

	i = 0;
	lil_len = ft_strlen((char *)little);
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && (i + lil_len) <= len)
	{
		if (ft_strncmp(&big[i], little, lil_len) == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
// int main()
// {
// 	const char *s1 = NULL;
// 	const char *s2 = NULL;
// 	size_t len = 40;
// 	printf ("%s\n", ft_strnstr(s1, s2, len));
// 	// printf ("%s\n", strnstr(s1, s2, len));
// }