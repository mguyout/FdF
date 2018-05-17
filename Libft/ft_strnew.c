/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 22:47:52 by mguyout           #+#    #+#             */
/*   Updated: 2016/11/16 12:55:30 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	if ((str = (char*)malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	str[size + 1] = '\0';
	size = -1;
	while (str[++size])
		str[size] = '\0';
	return (str);
}
