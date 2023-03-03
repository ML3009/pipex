/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:38:22 by ml                #+#    #+#             */
/*   Updated: 2023/03/03 11:14:07 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_charscount(char const *s, char c, size_t i)
{
	while (s[i] == c && s[i])
		i++;
	return (i);
}

static size_t	ft_wordscount(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (*s)
	{
		if (*s != c)
			i++;
		else if (*s == c && i != 0)
		{
			count++;
			i = 0;
		}
		s++;
	}
	if (i != 0)
		count++;
	return (count);
}

static size_t	ft_wordlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**ft_free(char **strings)
{
	size_t	i;

	i = 0;
	while (strings[i])
	{
		free (strings[i]);
		i++;
	}
	free (strings);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	size_t	i;
	size_t	j;
	char	**strings;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	strings = (char **)malloc(sizeof(char *) * (ft_wordscount(s, c) + 1));
	if (!strings)
		return (NULL);
	i = ft_charscount(s, c, i);
	while (j < ft_wordscount(s, c) && s[i])
	{
		strings[j] = ft_substr(s, i, ft_wordlen(&s[i], c));
		if (!strings)
			return (ft_free(&strings[j]));
		i += ft_wordlen(&s[i], c);
		j++;
		i = ft_charscount(s, c, i);
	}
	strings[j] = NULL;
	return (strings);
}
