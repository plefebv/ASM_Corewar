/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 12:41:25 by plefebvr          #+#    #+#             */
/*   Updated: 2016/03/21 20:44:02 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t buf;
	size_t lendst;
	size_t i;
	size_t lensrc;

	i = 0;
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	buf = lendst + lensrc;
	if (lendst < size)
	{
		while (i < (size - lendst) - 1)
		{
			dst[i + lendst] = src[i];
			i++;
		}
		dst[i + lendst] = '\0';
	}
	if (size < lendst)
		return (lensrc + size);
	else
		return (buf);
}
