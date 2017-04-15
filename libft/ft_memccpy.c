/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:26:55 by plefebvr          #+#    #+#             */
/*   Updated: 2016/03/21 20:44:02 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*dst2;
	char	*src2;

	i = 0;
	if (n == 0)
		return (NULL);
	dst2 = (char *)dst;
	src2 = (char *)src;
	while (i < n && src2[i] != c)
	{
		dst2[i] = src2[i];
		i++;
	}
	if (src2[i] == c)
	{
		dst2[i] = src2[i];
		return ((char *)&dst2[i + 1]);
	}
	else
		return (NULL);
}
