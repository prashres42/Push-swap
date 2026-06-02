/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 10:56:58 by prashres          #+#    #+#             */
/*   Updated: 2026/05/06 12:36:47 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static size_t	get_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i] && s[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

static void	ft_free(char **s, int c)
{
	while (c-- > 0)
		free(s[c]);
	free(s);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	index;

	i = 0;
	index = 0;
	if (!s)
		return (NULL);
	result = malloc ((count_word(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		result[index] = ft_substr(s, i, get_word(&s[i], c));
		if (!result[index])
			return (ft_free(result, index), NULL);
		i = i + get_word(&s[i], c);
		index++;
	}
	result[index] = NULL;
	return (result);
}

// int main(int ac, char **av)
// {
// 	if (ac != 3)
// 		return (1);
// 	char *s = av[1];
// 	char **d;
// 	size_t i = 0;
// 	char c = av[2][0];
// 	d = ft_split(s, c);
// 	while (d[i] != NULL)
// 	{
// 		printf("%s\n", d[i]);
// 		free(d[i]);
// 		i++;
// 	}
// 	free(d);
// 	return (0);
// }