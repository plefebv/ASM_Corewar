/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_work.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 19:14:13 by plefebvr          #+#    #+#             */
/*   Updated: 2016/11/23 17:16:19 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void				pf_work(void *ap, t_pffo *pffo)
{
	char *s;

	s = NULL;
	if (pffo->letter == 'd' || pffo->letter == 'i' || pffo->letter == 'o'
			|| pffo->letter == 'u' || pffo->letter == 'x'
			|| pffo->letter == 'X' || pffo->letter == 'p')
		pf_dioux(ap, pffo);
	else if (pffo->letter == 'c' || pffo->letter == 's')
		pf_sc(ap, pffo);
	else if (pffo->letter == '%' && (pffo->minfield))
		pf_treat_data(pffo);
	else if (pffo->letter != '?')
	{
		s = ft_strnew(1);
		s[0] = pffo->letter;
		pf_put_in_pst(pffo, s);
		pf_treat_data(pffo);
	}
}

void				pf_treat_data(t_pffo *pffo)
{
	if (pffo->minfield > 0 &&
			!(pffo->letter == 'd' || pffo->letter == 'i' || pffo->letter == 'o'
			|| pffo->letter == 'u' || pffo->letter == 'X' || pffo->letter == 'x'
			|| pffo->letter == 's'))
	{
		pf_char_minfield(pffo, (pffo->flags &&
					ft_strchr(pffo->flags, '-')) ? 1 : 0);
		if (pffo->letter == '%')
		{
			if (pffo->flags && ft_strchr(pffo->flags, '-'))
				pffo->pst->data = ft_strjoin_f2("%", pffo->pst->data);
			else
				pffo->pst->data = ft_strjoin_f1(pffo->pst->data, "%");
		}
	}
}

void				pf_hex2(void *ap, t_pffo *pffo)
{
	if ((pffo->flags && ft_strchr(pffo->flags, '#') &&
				((pffo->pst->data[0] != '0' &&
				pffo->letter != 'p'))) || pffo->letter == 'p')
		pffo->pst->data = (pffo->letter == 'x' || pffo->letter == 'p' ?
				ft_strjoin_f2("0x", pffo->pst->data) :
				ft_strjoin_f2("0X", pffo->pst->data));
	if (pffo->true_precision && !(pffo->flags && ft_strchr(pffo->flags, '#')))
		pf_precision_dioux(ap, pffo);
	if (pffo->true_precision && (pffo->letter == 'p' || (pffo->letter != 'p'
					&& pffo->flags && ft_strchr(pffo->flags, '#'))))
		pf_precision_p(ap, pffo);
	if (pffo->true_precision && pffo->letter == 'p'
			&& !pffo->precision && (int)ap == 0)
		pffo->pst->data = ft_strdup("0x");
	if (pffo->minfield > 0)
		pf_minfield(pffo);
}
