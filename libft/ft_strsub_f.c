/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 20:37:12 by plefebvr          #+#    #+#             */
/*   Updated: 2017/05/08 05:44:42 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub_f(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s2;

	i = 0;
	s2 = (char *)malloc(sizeof(*s2) * (len + 1));
	if (s2)
	{
		while (i < len)
		{
			s2[i] = s[start + i];
			i++;
		}
		s2[i] = '\0';
		ft_memdel((void **)&s);
		return (s2);
	}
	return (NULL);
}
