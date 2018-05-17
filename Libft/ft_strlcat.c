/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:11:33 by mguyout           #+#    #+#             */
/*   Updated: 2016/11/09 22:44:07 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	x;

	i = 0;
	while (dst[i] && i < size)
		i++;
	x = i;
	while (src[i - x] && i < size - 1)
	{
		dst[i] = src[i - x];
		i++;
	}
	if (x < size)
		dst[i] = '\0';
	return (ft_strlen(src) + x);
}
