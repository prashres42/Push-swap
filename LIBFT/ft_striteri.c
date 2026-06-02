/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:14:32 by prashres          #+#    #+#             */
/*   Updated: 2026/05/11 14:23:47 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
// void to_upper_all(unsigned int i, char *c)
// {
//     (void)i;
//     if(*c >= 'a' && *c <= 'z')
// 	{
// 		*c = *c- 32;
// 	}
// }
// 	int main()
// {
// 	// unsigned int i = 0;
//     char s[] = "dkhvcdn";
// 	// char *d = to_upper_all(i ,s);
// 	ft_striteri(s, to_upper_all);
//     printf("%s\n",s);
// }
