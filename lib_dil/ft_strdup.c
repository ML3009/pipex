/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:17:47 by ml                #+#    #+#             */
/*   Updated: 2023/01/24 19:44:34 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strdup(char *src)
{
    char    *new;
    size_t  i;

    i = 0;
    new = (char *)malloc(ft_strlen(src) + 1);
    if (!new)
        return (NULL);
    while(src[i])
    {
        new[i] = src[i];
        i++;
    }
    new[i] = '\0';
    return (new);
}