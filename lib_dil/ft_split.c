/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:52:27 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/18 14:58:45 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_string(char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] && s[j] == c)
			j++;
		if (!(s[j]))
			break ;
		i++;
		while (s[j] && s[j] != c)
			j++;
	}
	return (i);
}

static char	*len_string(char *s, char c)
{
	int		len;
	char	*sa;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	sa = malloc(len + 1);
	if (!sa)
		return (NULL);
	sa[len] = 0;
	while (len > 0)
	{
		sa[len - 1] = s[len - 1];
		len --;
	}
	return (sa);
}

static void	ft_free(char **strings, int i)
{
	while (i)
	{
		free (strings[i]);
		i--;
	}
	free (strings);
}

char	**ft_split(char *s, char c)
{
	char	**strings;
	int		n;

	n = 0;
	strings = malloc((count_string (s, c) + 1) * sizeof (char *));
	if (!strings)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!(*s))
			break ;
		strings[n++] = len_string(s, c);
		if (!strings[n - 1])
		{
			ft_free(strings, n);
			return (strings);
		}
		while (*s && *s != c)
			s++;
	}
	strings[n] = NULL;
	return (strings);
}
