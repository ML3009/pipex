/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:20:27 by ml                #+#    #+#             */
/*   Updated: 2023/02/15 12:05:31 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int ft_strncmp(char *s1, char *s2, size_t n)
{
    while((*s1 || *s2) && (n > 0))
    {
        if(*s1 != *s2)
        {
            return ((unsigned char)*s1 - (unsigned char)*s2);
            s1++;
            s2++;
            n--;
        }
    }
    return(0);
}*/

int    ft_strncmp(const char *s1, const char *s2, size_t n)
{
    while (n > 0 && (*s1 == *s2) && *s1)
    {
        s1++;
        s2++;
        n--;
    }
    if (n == 0)
        return (0);
    return ((unsigned char)(*s1) - (unsigned char)(*s2));
}
