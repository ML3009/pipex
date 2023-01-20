/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:04:05 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/16 17:13:27 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *line, char *buf)
{
	char	*tab;
	char	*new;
	int		size;
	int		i;

	i = 0;
	size = (ft_strlen(line) + ft_strlen(buf));
	tab = malloc (sizeof(char) * (size + 1));
	new = tab;
	if (!new)
		return (NULL);
	while (line && line[i])
	{
		tab[i] = line[i];
		i++;
	}
	while (*buf)
	{
		tab[i++] = *buf++;
	}
	tab[size] = '\0';
	free (line);
	return (new);
}
