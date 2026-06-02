/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 13:58:53 by prashres          #+#    #+#             */
/*   Updated: 2026/05/11 14:18:14 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	result = malloc(sizeof (char) * (ft_strlen(s) + 1));
	if (!result)
		return (NULL);
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
// char    my_func(unsigned int i, char c)
// {	
// 	printf("%d\n", i);
//     if (i % 2 == 0)
//         return (ft_toupper(c));
//     else
//         return (ft_tolower(c));
// }
// char to_upper_all(unsigned int i, char c)
// {
//     (void)i;
//     return (ft_toupper(c));
// }
// int main()
// {
//     char *s;

//     s = ft_strmapi("dkhvcdn ", my_func);
//     printf("%s\n", s);
//     free (s);
// }