/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 03:00:16 by plefebvr          #+#    #+#             */
/*   Updated: 2016/11/23 15:57:30 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_printf(const char *fmt, ...)
{
	t_pffo		pffo;
	va_list		ap;
	int			i;

	i = 0;
	va_start(ap, fmt);
	pf_init_strct(&pffo);
	while (fmt && fmt[i] != '\0')
	{
		pf_epur_fmt(&pffo, fmt, &i);
		if (fmt[i] && fmt[i] == '%')
		{
			pf_parse_arg(fmt, &i, &pffo, ap);
			pf_work(pffo.letter != '%' ? va_arg(ap, void *) : NULL, &pffo);
			pf_clean_pffo(&pffo);
		}
	}
	va_end(ap);
	return (pf_print_list(&pffo));
}
