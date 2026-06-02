/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:18:14 by prashres          #+#    #+#             */
/*   Updated: 2026/05/11 14:11:47 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	end(char const *s1, char const *set)
{
	size_t	j;

	j = ft_strlen(s1) - 1;
	while (j > 0)
	{
		if (ft_strchr(set, s1[j]))
			j--;
		else
			break ;
	}
	return (j);
}

static size_t	start(char const *s1, char const *set)
{
	size_t	j;

	j = 0;
	while (s1[j])
	{
		if (ft_strchr(set, s1[j]))
			j++;
		else
			break ;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	j = end (s1, set);
	i = start (s1, set);
	if (i > j)
		return (ft_strdup(""));
	trimmed = malloc((j - i + 2) * sizeof(char));
	if (!trimmed)
		return (NULL);
	ft_memcpy(trimmed, s1 + i, (j - i + 1));
	trimmed[j - i + 1] = '\0';
	return (trimmed);
}
// #include <stdio.h>
// int main()
// {
// 	char const *s1 = "xyzthisishtdxebestyxxyz";
// 	char const *set = "xyz";
// 	printf("%s", ft_strtrim (s1, set));
// }