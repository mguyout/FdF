/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:26:05 by mguyout           #+#    #+#             */
/*   Updated: 2017/03/18 04:00:19 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_malloc_fd(char const *s, char c)
{
	int		i;
	int		words;
	char	**tab;

	words = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] != c && i < ft_strlen(s))
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	if (words == 0)
		words++;
	if ((tab = (char**)malloc(sizeof(char*) * (words + 2))) == 0)
		return (NULL);
	return (tab);
}

static char		**ft_malloc_sd(char const *s, char c, char **tab)
{
	int		i;
	int		len;
	int		x;

	x = -1;
	len = 0;
	i = -1;
	while (s[++i] && i < ft_strlen(s))
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c && i < ft_strlen(s))
			{
				i++;
				len++;
			}
			if ((tab[++x] = (char*)malloc(sizeof(char) * (len + 2))) == 0)
				return (NULL);
			len = 0;
		}
	}
	return (tab);
}

static char		**ft_check(char const *s, char c)
{
	char	**tab;

	if (s)
	{
		if (!(tab = ft_malloc_fd(s, c)))
			return (NULL);
		if (!(tab = ft_malloc_sd(s, c, tab)))
			return (NULL);
		return (tab);
	}
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		x;
	int		j;

	j = -1;
	x = 0;
	i = -1;
	if (!(tab = ft_check(s, c)))
		return (NULL);
	while (s[++i])
	{
		if (s[i] != c && i < ft_strlen(s))
		{
			while (s[i] && s[i] != c && i < ft_strlen(s))
				tab[x][++j] = s[i++];
			tab[x][j + 1] = '\0';
			j = -1;
			x++;
		}
	}
	tab[x] = NULL;
	return (tab);
}
