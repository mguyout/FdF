/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:08:25 by mguyout           #+#    #+#             */
/*   Updated: 2016/11/16 16:23:31 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*str;

	if (s && f)
	{
		len = ft_strlen(s);
		i = -1;
		if ((str = (char*)malloc(sizeof(char) * (len + 1))) == 0)
			return (NULL);
		while (s[++i])
			str[i] = f(i, s[i]);
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
