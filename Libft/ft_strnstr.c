/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:27:27 by mguyout           #+#    #+#             */
/*   Updated: 2016/11/19 18:49:20 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	n;

	n = (size_t)ft_strlen((char *)little);
	i = 0;
	while (big[i] && (i + n <= len))
	{
		if (ft_strncmp(big + i, little, n) == 0)
			return ((char *)big + i);
		++i;
	}
	return (NULL);
}
