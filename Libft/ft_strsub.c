/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:00:56 by mguyout           #+#    #+#             */
/*   Updated: 2017/04/04 05:19:39 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;

	i = -1;
	if (s && (int)start <= ft_strlen(s))
	{
		if ((str = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
		s += start;
		while (++i < len)
			str[i] = s[i];
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
