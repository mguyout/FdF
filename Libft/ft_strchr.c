/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 21:05:41 by mguyout           #+#    #+#             */
/*   Updated: 2017/04/04 04:48:16 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if ((char)c == '\0')
	{
		while (s[i])
			i++;
		return ((char*)s + i);
	}
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char*)s + i);
		i++;
	}
	return (NULL);
}
