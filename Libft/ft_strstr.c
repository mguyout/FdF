/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:27:27 by mguyout           #+#    #+#             */
/*   Updated: 2016/11/09 20:36:19 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcmp_custom(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char		*ft_strstr(const char *big, const char *little)
{
	int i;

	i = -1;
	if (little[0] == 0)
		return ((char*)big);
	while (big[++i])
		if (big[i] == little[0])
			if (ft_strcmp_custom(little, big + i) == 0)
				return ((char*)big + i);
	return (NULL);
}
