/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_first_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 18:02:07 by plefebvr          #+#    #+#             */
/*   Updated: 2016/11/23 17:16:19 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		pf_stars(int value, t_pffo *pffo, int *i, const char *fmt)
{
	if (pffo->star_minfield)
	{
		pffo->minfield = value;
		(pffo->star_minfield)--;
		(pffo->stars)--;
	}
	else if (pffo->star_precision)
	{
		pffo->precision = value;
		(pffo->star_precision)--;
		(pffo->stars)--;
	}
	while (ft_isdigit(fmt[*i]))
		(*i)++;
}

void		pf_clean_pffo(t_pffo *pffo)
{
	if (pffo->flags)
		ft_memdel((void **)&pffo->flags);
	pffo->minfield = 0;
	pffo->star_minfield = 0;
	pffo->true_precision = 0;
	pffo->precision = 0;
	pffo->star_precision = 0;
	if (pffo->length)
		ft_memdel((void **)&pffo->length);
	pffo->letter = '?';
	pffo->stars = 0;
	pffo->sign = '+';
}

void		pf_epur_fmt(t_pffo *pffo, const char *fmt, int *i)
{
	int		tmp;
	char	*data;

	tmp = *i;
	data = NULL;
	while (fmt[*i] && fmt[*i] != '%')
		*i += 1;
	data = ft_strsub(fmt, tmp, *i - tmp);
	if (ft_strlen(data))
		pf_put_in_pst(&pffo[0], data);
	else
		ft_memdel((void **)&data);
}

int			pf_dio(t_pffo *pffo)
{
	if (pffo->letter == 'd' || pffo->letter == 'i')
		return (1);
	return (0);
}
