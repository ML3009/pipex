/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:14:11 by ml                #+#    #+#             */
/*   Updated: 2023/03/05 20:25:17 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
    char    *tab;
    char    *new;
    int        size;
    int        i;

    i = 0;
    size = (ft_strlen(s1) + ft_strlen(s2));
    tab = malloc (sizeof(char) * (size + 1));
    new = tab;
    if (!new)
    {
        free(tab);
        return (NULL);
    }
    while (s1 && s1[i])
    {
        tab[i] = s1[i];
        i++;
    }
    while (*s2)
        tab[i++] = *s2++;
    tab[size] = '\0';
    free (s1);
    return (new);
}
