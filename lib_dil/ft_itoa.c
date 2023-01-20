/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:12:06 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/02 12:11:03 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_size(int n)
{
	int	count;

	count = 0;
	if (n < 0 && n > -2147483648)
	{
		count ++;
		n = -n;
	}
	else if (n == 0)
		return (1);
	else if (n == -2147483648)
		return (11);
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	j;
	long	nb;
	char	*string;

	j = (ft_itoa_size(n));
	nb = n;
	string = malloc(j + 1);
	if (!(string))
		return (NULL);
	i = 0;
	if (nb < 0)
	{
		string[i++] = '-';
		nb *= -1;
	}
	string[j] = 0;
	while (j > i)
	{
		string[--j] = nb % 10 + '0';
		nb /= 10;
	}
	return (string);
}
