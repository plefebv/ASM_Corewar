/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 12:24:56 by plefebvr          #+#    #+#             */
/*   Updated: 2016/11/23 17:16:19 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void			pf_convert_to_wchar(wchar_t ap, t_pffo *pffo)
{
	if (ap < 128)
		pffo->pst->data[0] = ((ap >> 0) & 127) | 0;
	else if (ap < 2048)
	{
		pffo->pst->data[0] = ((ap >> 6) & 31) | 192;
		pffo->pst->data[1] = ((ap >> 0) & 63) | 128;
	}
	else if (ap < 65536)
	{
		pffo->pst->data[0] = ((ap >> 12) & 15) | 224;
		pffo->pst->data[1] = ((ap >> 6) & 63) | 128;
		pffo->pst->data[2] = ((ap >> 0) & 63) | 128;
	}
	else if (ap < 1114112)
	{
		pffo->pst->data[0] = ((ap >> 18) & 7) | 240;
		pffo->pst->data[1] = ((ap >> 12) & 63) | 128;
		pffo->pst->data[2] = ((ap >> 6) & 63) | 128;
		pffo->pst->data[3] = ((ap >> 0) & 63) | 128;
	}
}

void				pf_put_wc(wchar_t ap, t_pffo *pffo)
{
	if (ap < 1114112)
	{
		free(pffo->pst->data);
		if (ap < 128)
			pffo->pst->data = ft_strnew(1);
		else if (ap < 2048)
			pffo->pst->data = ft_strnew(2);
		else if (ap < 65536)
			pffo->pst->data = ft_strnew(3);
		else if (ap < 1114112)
			pffo->pst->data = ft_strnew(4);
		pf_convert_to_wchar(ap, pffo);
	}
}

void				pf_put_char(char ap, t_pffo *pffo)
{
	char tmp[2];

	tmp[1] = '\0';
	tmp[0] = ap;
	free(pffo->pst->data);
	pffo->pst->data = (char *)malloc(sizeof(char) * 2);
	if (pffo->pst->data)
	{
		pffo->pst->data[0] = ap;
		pffo->pst->data[1] = '\0';
	}
}
