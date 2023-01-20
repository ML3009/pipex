/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:11:34 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/02 12:11:38 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_printf(const char *str_arg, ...)
{
	int		i;
	int		len;
	va_list	ptr;

	i = 0;
	len = 0;
	va_start (ptr, str_arg);
	while (str_arg[i])
	{
		if (str_arg[i] == '%' && str_arg[i])
		{
			len += ft_convert_arg (str_arg[i + 1], ptr);
			i++;
		}
		else
			len += ft_putchar (str_arg[i]);
	i++;
	}
	va_end (ptr);
	return (len);
}

int	ft_convert_arg(const char str_arg, va_list ptr)
{
	int		len;

	len = 0;
	if (str_arg == 'c')
		len += ft_putchar ((va_arg(ptr, int)));
	if (str_arg == 's')
		len += ft_putstr (va_arg(ptr, char *));
	if (str_arg == 'p')
		len += ft_putaddr (va_arg(ptr, uintptr_t));
	if (str_arg == 'd' || str_arg == 'i')
		len += ft_putnbr (va_arg(ptr, int));
	if (str_arg == 'u')
		len += ft_unsign_nb (va_arg(ptr, unsigned int));
	if (str_arg == 'x')
		len += ft_hexa_min (va_arg(ptr, unsigned int));
	if (str_arg == 'X')
		len += ft_hexa_max(va_arg(ptr, unsigned int));
	if (str_arg == '%')
		len += ft_putchar('%');
	return (len);
}
