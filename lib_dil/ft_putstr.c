/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:10:46 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/02 12:11:03 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *s)
{
	int	i;
	int	len;

	len = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		len += ft_putchar (s[i]);
		i++;
	}
	return (len);
}
