/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 21:25:25 by plefebvr          #+#    #+#             */
/*   Updated: 2016/03/21 20:44:02 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	size_t b;
	size_t i;
	size_t z;

	b = 0;
	i = 0;
	z = ft_strlen(s);
	b = z;
	if (s == NULL)
		return (NULL);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	while ((s[z] == ' ' || s[z] == '\n' || s[z] == '\t'
				|| s[z] == '\0') && z > i)
		z--;
	z++;
	return (ft_strsub(s, i, (b - (i + (b - z)))));
}
