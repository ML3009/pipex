/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsign_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:06:17 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/02 12:11:03 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unsign_nb(unsigned int nb)
{
	long long int	i;
	int				len;

	len = 0;
	i = nb;
	if (i > 9)
	{
		len += ft_putnbr (i / 10);
		len += ft_putchar (i % 10 + '0');
	}
	else
	len += ft_putchar (i + '0');
	return (len);
}
