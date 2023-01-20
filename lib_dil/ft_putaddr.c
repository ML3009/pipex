/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:12:45 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/02 12:11:23 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_putaddr(uintptr_t nb)
{
	char	*base;
	int		len;

	len = 0;
	if (!nb)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	else
	{
		len += ft_putstr ("0x");
		base = "0123456789abcdef";
	}
	if (nb >= 16)
	{
		len += ft_hexa_ptr (nb / 16);
		len += ft_putchar (base [nb % 16]);
	}
	else
		len += ft_putchar (base[nb]);
	return (len);
}

int	ft_hexa_ptr(unsigned long long nb)
{
	char	*base;
	int		len;

	len = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		len += ft_hexa_ptr (nb / 16);
		len += ft_putchar (base [nb % 16]);
	}
	else
		len += ft_putchar (base[nb]);
	return (len);
}
