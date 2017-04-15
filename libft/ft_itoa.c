/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:26:56 by plefebvr          #+#    #+#             */
/*   Updated: 2016/09/28 19:04:42 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_nlen(int n)
{
	int i;
	int nb;

	i = 0;
	nb = n;
	if (n == 0)
		return (1);
	if (nb < 0)
		i++;
	while (nb)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_nlen(n) - 1;
	if ((str = (char *)malloc(sizeof(*str) * (ft_nlen(n) + 1))))
	{
		str[i + 1] = '\0';
		if (n < 0)
		{
			str[0] = '-';
			n = -n;
		}
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
