/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:40:59 by prashres          #+#    #+#             */
/*   Updated: 2026/05/13 13:59:17 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (s[i] == (char)c)
	{
		return ((char *)&s[i]);
	}
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	return (NULL);
}
// int main ()
// {
// 	char *s = "sdfgdg";
// 	int a = 's';
// 	printf("%s\n", ft_strrchr(s , a));
// 	printf("%s\n", strrchr(s , a));
// }