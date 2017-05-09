/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 10:10:19 by plefebvr          #+#    #+#             */
/*   Updated: 2017/05/09 14:48:45 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	convert_str(char c, int base)
{
	int		ret;

	if (c >= '0' && c <= '9')
		ret = c - 48;
	else if (c >= 'a' && c <= 'z')
		ret = c - 87;
	else if (c >= 'A' && c <= 'Z')
		ret = c - 66;
	else
		ret = -1;
	if (ret < base && ret != - 1)
		return (ret);
	return (-1);
}


static int	lgt_nbr(char *str, int base)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (convert_str(str[i], base) == -1)
			break ;
		i++;
	}
	return (i);
}

int			ft_atoi_base_f(char *str, int base)
{
	int		ret;
	int		lgt;

	if (base == 10)
		return (ft_atoi(str));
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r')
		str++;
	ret = 0;
	lgt = lgt_nbr(str, base) - 1;
	while (*str && lgt >= 0 && convert_str(*str, base) != - 1)
	{
		ret += convert_str(*str, base) * ft_power(base, lgt);
		str++;
		lgt--;
	}
	ft_memdel((void **)&str);
	return (ret);
}
