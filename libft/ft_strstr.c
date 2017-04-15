/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:27:25 by plefebvr          #+#    #+#             */
/*   Updated: 2016/03/21 20:44:02 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (s2[j] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		while (s2[j] == s1[i + j] && s2[j] != '\0')
		{
			j++;
			if (s2[j] == '\0')
				return ((char *)&s1[i]);
			else if (s1[i + j] == '\0')
				return (NULL);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
