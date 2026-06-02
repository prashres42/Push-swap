/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prashres <prashres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 11:47:30 by prashres          #+#    #+#             */
/*   Updated: 2026/05/14 11:32:30 by prashres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*result;

	nb = n;
	len = get_len(nb);
	result = malloc(sizeof (char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (nb == 0)
		result[0] = '0';
	if (nb < 0)
	{
		nb = -nb;
		result[0] = '-';
	}
	while (nb)
	{
		len--;
		result[len] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (result);
}
// int main()
// {
// 	int n = 0;	
// 	printf("%s", ft_itoa(n));
// }