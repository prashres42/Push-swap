/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:45:38 by prashres          #+#    #+#             */
/*   Updated: 2026/05/11 14:24:48 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s2;
	size_t	i;

	i = ft_strlen(s);
	s2 = malloc((i + 1) * sizeof (char));
	if (!s2)
		return (NULL);
	ft_memcpy (s2, s, i + 1);
	return (s2);
}
// char	*ft_strdup(const char *s)
// {
// 	char *dup;
// 	size_t i;
// 	int j;

// 	i = ft_strlen(s);
// 	dup = malloc(sizeof(char) * (i + 1));
// 	if (!dup)
// 		return (NULL);
// 	j = 0;
// 	while(s[j])
// 	{
// 		dup[j] = s[j];
// 		j++;
// 	}
// 	dup[j] = '\0';
// 	return (dup);
// }
// int main()
// {
// 	char *s = "";
// 	char *d = ft_strdup(s);

// 	printf("%s",d);
// }
