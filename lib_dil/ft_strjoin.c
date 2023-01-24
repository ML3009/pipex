/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:14:11 by ml                #+#    #+#             */
/*   Updated: 2023/01/24 19:46:53 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strjoin(char *s1, char *s2)
{
    char    *strings;
    size_t  i;
    size_t  j;

    strings = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!strings)
        return(NULL);
    i = 0;
    while (s1[i])
    {
        strings[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j])
    {
        strings[i] = s2[j];
        i++;
        j++;
    }
    strings[i] = '\0';
    return(strings);
}
