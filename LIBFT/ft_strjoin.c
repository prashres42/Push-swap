/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:48:06 by prashres          #+#    #+#             */
/*   Updated: 2026/05/11 14:22:45 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	new = malloc((i + j + 1) * sizeof (char));
	if (!new)
		return (NULL);
	ft_memcpy (new, s1, i);
	ft_memcpy (new + i, s2, j);
	new [i + j] = '\0';
	return (new);
}
// int main()
// {
// 	char const*s1= "";
// 	char const *s2 = "";
// 	printf("%s", ft_strjoin(s1, s2));
// }