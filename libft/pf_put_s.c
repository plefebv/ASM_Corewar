/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 12:23:19 by plefebvr          #+#    #+#             */
/*   Updated: 2016/11/23 17:16:19 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void						pf_convert_ws_to_s(wchar_t ap, \
								int i, t_pffo *pffo)
{
	if (ap < 128)
		pffo->pst->data[i] = ((ap >> 0) & 127) | 0;
	else if (ap < 2048)
	{
		pffo->pst->data[i] = ((ap >> 6) & 31) | 192;
		pffo->pst->data[i + 1] = ((ap >> 0) & 63) | 128;
	}
	else if (ap < 65536)
	{
		pffo->pst->data[i] = ((ap >> 12) & 15) | 224;
		pffo->pst->data[i + 1] = ((ap >> 6) & 63) | 128;
		pffo->pst->data[i + 2] = ((ap >> 0) & 63) | 128;
	}
	else if (ap < 1114112)
	{
		pffo->pst->data[i] = ((ap >> 18) & 7) | 240;
		pffo->pst->data[i + 1] = ((ap >> 12) & 63) | 128;
		pffo->pst->data[i + 2] = ((ap >> 6) & 63) | 128;
		pffo->pst->data[i + 3] = ((ap >> 0) & 63) | 128;
	}
}

static unsigned int				pf_size_ws(wchar_t *ap)
{
	int		i;
	int		q;

	i = 0;
	q = 0;
	while (*ap)
	{
		if (*ap < 128)
			q++;
		else if (*ap < 2048)
			q += 2;
		else if (*ap < 65536)
			q += 3;
		else if (*ap < 1114112)
			q += 4;
		ap++;
	}
	return (q);
}

static int						pf_size_wc(wchar_t ap)
{
	int		ret;

	ret = 0;
	if (ap < 128)
		ret++;
	else if (ap < 2048)
		ret += 2;
	else if (ap < 65536)
		ret += 3;
	else if (ap < 1114112)
		ret += 4;
	return (ret);
}

void							pf_put_ws(void *ap, t_pffo *pffo)
{
	int		i;
	int		q;
	wchar_t *str;

	i = 0;
	q = 0;
	str = ap;
	pf_put_in_pst(pffo, ft_strdup(""));
	free(pffo->pst->data);
	pffo->pst->data = ft_strnew(pf_size_ws(str));
	while (str[i] != '\0' && ((pffo->true_precision &&
					q + pf_size_wc(str[i]) <= pffo->precision)
					|| !pffo->true_precision))
	{
		pf_convert_ws_to_s(str[i], q, pffo);
		q += pf_size_wc(str[i++]);
	}
}
