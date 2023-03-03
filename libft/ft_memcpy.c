/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:28:15 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/18 14:36:37 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t	i;
	char	*dst1;
	char	*src1;

	if (!dst && !src)
		return (NULL);
	dst1 = (char *)dst;
	src1 = (char *)src;
	i = 0;
	while (i < n)
	{
		dst1[i] = src1[i];
	i++;
	}
	return (dst1);
}
