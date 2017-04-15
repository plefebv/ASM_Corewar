/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_null.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 15:53:50 by plefebvr          #+#    #+#             */
/*   Updated: 2016/11/23 17:16:19 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*pf_strjoin_c_null(char *s1, t_pffo *pffo, unsigned long long mfw)
{
	char					*s3;
	unsigned long long		len;
	unsigned long long		i;
	unsigned long long		j;
	unsigned long long		tmp;

	i = -1;
	j = 0;
	tmp = ft_strlen(pffo->pst->data);
	pffo->ret += tmp;
	len = pffo->ret + mfw + 1;
	s3 = (char *)malloc(sizeof(*s3) * (len + 300 + 1));
	if (s3)
	{
		while (s1 && ++i < pffo->ret - tmp)
			s3[i] = s1[i];
		while (s1 && i < pffo->ret + mfw + 1)
			s3[i++] = pffo->pst->data[j++];
		s3[i] = '\0';
		return (s3);
	}
	else
		return (NULL);
}
