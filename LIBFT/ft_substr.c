/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:37:01 by prashres          #+#    #+#             */
/*   Updated: 2026/05/11 11:56:38 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen (s);
	if (start >= j)
		return (ft_strdup(""));
	if (len > j - start)
		len = j - start;
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (len--)
	{
		ret[i] = s[start];
		i++;
		start++;
	}
	ret[i] = '\0';
	return (ret);
}

/* int main()
{
	char const *s = "This is the beginning";
	size_t start = 7;
	size_t len = 3;
	char *ret = ft_substr(s, start, len);
	printf("%s", ret);
} */