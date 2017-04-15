/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:38:06 by plefebvr          #+#    #+#             */
/*   Updated: 2016/09/25 18:29:56 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin_f(char const *s1, char const *s2)
{
	char	*s3;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	s3 = (char *)malloc(sizeof(*s3) * (len + 1));
	if (s3)
	{
		while (s1[i] != '\0')
		{
			s3[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
			s3[i++] = s2[j++];
		s3[i] = '\0';
		ft_memdel((void **)&s1);
		ft_memdel((void **)&s2);
		return (s3);
	}
	else
		return (NULL);
}
