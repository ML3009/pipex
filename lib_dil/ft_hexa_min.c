/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:29:37 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/02 12:11:03 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexa_min(unsigned int nb)
{
	char	*base;
	int		len;

	len = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		len += ft_hexa_min (nb / 16);
		len += ft_putchar (base [nb % 16]);
	}
	else
		len += ft_putchar (base[nb]);
	return (len);
}
