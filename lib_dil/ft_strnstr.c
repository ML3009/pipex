/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:55:50 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/18 14:48:20 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *big, char *little, size_t len)
{
	size_t	i;
	size_t	lenbis;

	i = 0;
	lenbis = ft_strlen((char *)little);
	if (!big && len == 0)
		return (NULL);
	if (lenbis == 0)
		return ((char *)big);
	while (big[i] && len)
	{
		if (ft_strncmp((char *)&big[i], (char *)little, lenbis) == 0
			&& lenbis <= len)
		{
			if ((i + lenbis) > len)
				return (NULL);
			return ((char *)&big[i]);
		}
	i++;
	}
	return (NULL);
}
