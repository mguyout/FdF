/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 13:06:28 by mguyout           #+#    #+#             */
/*   Updated: 2016/11/16 14:11:00 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		x;
	int		j;
	char	*str;

	i = -1;
	j = -1;
	if (s)
	{
		x = ft_strlen(s);
		while ((s[x - 1] == '\t' || s[x - 1] == ' ' || s[x - 1] == '\n'))
			x--;
		while ((s[++i] == '\t' || s[i] == ' ' || s[i] == '\n'))
			x--;
		if (x <= 0)
			x = 0;
		if ((str = (char*)malloc(sizeof(char) * (x + 1))) == 0)
			return (NULL);
		s = s + i;
		while (++j < x)
			str[j] = s[j];
		str[j] = '\0';
		return (str);
	}
	return (0);
}
