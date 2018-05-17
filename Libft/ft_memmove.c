/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 22:20:06 by mguyout           #+#    #+#             */
/*   Updated: 2017/01/07 19:04:02 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	i = 0;
	if (src > dst)
		while (len--)
			((char*)dst)[i++] = *((char*)src++);
	else
		while (len--)
			*((char*)dst + len) = *((char*)src + len);
	return (dst);
}
