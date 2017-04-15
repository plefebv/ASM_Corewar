/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 18:04:25 by plefebvr          #+#    #+#             */
/*   Updated: 2016/11/23 15:52:33 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void			pf_put_flag(const char *fmt, int *i, t_pffo *pffo)
{
	int		tmp;

	tmp = *i;
	while (fmt[*i + 1] == '-' || fmt[*i + 1] == '+' || fmt[*i + 1] == ' '
			|| fmt[*i + 1] == '#' || fmt[*i + 1] == '0')
		*i += 1;
	if (*i > tmp)
		pffo->flags = ft_strsub(fmt, tmp + 1, *i - tmp);
	else
		pffo->flags = NULL;
}

static void			pf_put_mfw(const char *fmt, int *i, \
					t_pffo *pffo, va_list ap)
{
	int		tmp;
	char	*str;

	tmp = *i;
	str = NULL;
	while ((ft_isdigit(fmt[*i + 1])))
		(*i)++;
	if (fmt[*i + 1] == '*')
	{
		if (fmt[*i + 1] == '*' && !(fmt[*i + 2] && ft_isdigit(fmt[*i + 2])))
			pffo->minfield = va_arg(ap, int);
		else if (fmt[*i + 1] == '*')
			va_arg(ap, int);
		(*i)++;
		tmp = *i;
		while ((ft_isdigit(fmt[*i + 1])))
			(*i)++;
	}
	if (*i > tmp)
	{
		str = ft_strsub(fmt, tmp + 1, *i - tmp);
		pffo->minfield = ft_atoi(str);
		ft_memdel((void **)&str);
	}
	pf_put_mfw2(pffo);
}

static void			pf_put_precision(const char *fmt, int *i, \
					t_pffo *pffo, va_list ap)
{
	int		tmp;
	char	*str;

	tmp = *i;
	str = NULL;
	if (fmt[*i + 1] == '.')
	{
		pffo->true_precision = 1;
		(*i)++;
		while ((ft_isdigit(fmt[*i + 1])))
			(*i)++;
		if (fmt[*i + 1] == '*')
		{
			pffo->precision = va_arg(ap, int);
			(*i)++;
		}
		else if (tmp < *i)
		{
			str = ft_strsub(fmt, tmp + 2, *i - tmp - 1);
			pffo->precision = ft_atoi(str);
			ft_memdel((void**)&str);
		}
	}
}

static void			pf_put_length(const char *fmt, int *i, t_pffo *pffo)
{
	int tmp;

	tmp = *i;
	if (fmt[*i + 1] == 'h' && fmt[*i + 2] == 'h')
	{
		*i += 2;
		pffo->length = ft_strdup("hh");
	}
	if (fmt[*i + 1] == 'l' && fmt[*i + 2] == 'l')
	{
		*i += 2;
		pffo->length = ft_strdup("ll");
	}
	if (fmt[*i + 1] == 'h' || fmt[*i + 1] == 'l' || fmt[*i + 1] == 'j'
			|| fmt[*i + 1] == 'z')
	{
		(*i)++;
		pffo->length = ft_strsub(&fmt[*i], 0, 1);
	}
	while (fmt[*i + 1] == 'h' || fmt[*i + 1] == 'l' ||
			fmt[*i + 1] == 'j' || fmt[*i + 1] == 'z')
		(*i)++;
}

void				pf_parse_arg(const char *fmt, int *i, \
					t_pffo *pffo, va_list ap)
{
	pf_put_flag(fmt, i, pffo);
	pf_put_mfw(fmt, i, pffo, ap);
	pf_put_precision(fmt, i, pffo, ap);
	pf_put_length(fmt, i, pffo);
	pf_put_letter(fmt, i, pffo);
}
