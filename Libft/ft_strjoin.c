/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 14:12:08 by mguyout           #+#    #+#             */
/*   Updated: 2016/11/16 14:17:54 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*str;
	int		i;
	int		x;

	i = -1;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if ((str = (char*)malloc(sizeof(char*) * (len + 1))) == 0)
			return (NULL);
		while (s1[++i])
			str[i] = s1[i];
		x = i;
		i = -1;
		while (s2[++i])
			str[i + x] = s2[i];
		str[i + x] = '\0';
		return (str);
	}
	return (NULL);
}
