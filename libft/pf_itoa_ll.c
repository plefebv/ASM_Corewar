/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:26:56 by plefebvr          #+#    #+#             */
/*   Updated: 2016/11/23 15:52:33 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static long long		pf_nlen(long long n)
{
	long long	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static long long		pf_nlen_u(unsigned long long n)
{
	long long			i;

	i = 0;
	if (n == 0)
		return (1);
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char					*pf_itoa_ll(long long n, t_pffo *pffo)
{
	char				*str;
	long long			i;
	unsigned long long	j;

	i = n >= 0 ? pf_nlen(n) : pf_nlen(-n);
	str = NULL;
	pffo->sign = n < 0 ? '-' : '+';
	j = n >= 0 ? n : -n;
	if (n >= 9223372036854775807)
		return (ft_strdup("9223372036854775807"));
	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	if ((str = (char *)ft_memalloc(sizeof(char) * (i + 2))))
	{
		str[i + 1] = '\0';
		if (j == 0)
			str[0] = '0';
		while (j > 0)
		{
			str[i--] = (j % 10) + 48;
			j = j / 10;
		}
		return (str);
	}
	return (NULL);
}

char					*pf_itoa_ull(unsigned long long n)
{
	char			*str;
	long long		i;

	i = pf_nlen_u(n);
	if ((str = (char *)ft_memalloc(sizeof(char) * (i + 2))))
	{
		str[i + 1] = '\0';
		if (n == 0)
			str[0] = '0';
		while (n > 0)
		{
			str[i--] = (n % 10) + 48;
			n = n / 10;
		}
		return (str);
	}
	else
		return (NULL);
}
