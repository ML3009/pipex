/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:17:53 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/18 14:54:41 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*tab;

	if (!s)
		return (NULL);
	i = 0;
	tab = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!tab)
		return (NULL);
	while (i < (ft_strlen((char *)s)))
	{
		tab[i] = f(i, s[i]);
	i++;
	}
	tab[i] = '\0';
	return (tab);
}
