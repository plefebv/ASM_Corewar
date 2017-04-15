/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_di.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 13:03:51 by plefebvr          #+#    #+#             */
/*   Updated: 2016/11/23 17:16:19 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		pf_di_length(void *ap, t_pffo *pffo)
{
	if (ft_strcmp("hh", pffo->length) == 0)
		pf_put_in_pst(pffo, pf_itoa_ll((char)ap, pffo));
	else if (ft_strcmp("h", pffo->length) == 0)
		pf_put_in_pst(pffo, pf_itoa_ll((short)ap, pffo));
	else if (ft_strcmp("l", pffo->length) == 0)
		pf_put_in_pst(pffo, pf_itoa_ll((long)ap, pffo));
	else if (ft_strcmp("ll", pffo->length) == 0)
		pf_put_in_pst(pffo, pf_itoa_ll((long long)ap, pffo));
	else if (ft_strcmp("j", pffo->length) == 0)
		pf_put_in_pst(pffo, pf_itoa_ll((intmax_t)ap, pffo));
	else if (ft_strcmp("z", pffo->length) == 0)
		pf_put_in_pst(pffo, pf_itoa_ll((size_t)ap, pffo));
}

void		pf_di(void *ap, t_pffo *pffo)
{
	int		i;

	i = 0;
	pffo->length ? pf_di_length(ap, pffo) :
	pf_put_in_pst(pffo, pf_itoa_ll((signed)ap, pffo));
	if (pffo->true_precision)
		pf_precision_dioux(ap, pffo);
	if (pffo->minfield > 0)
		pf_minfield(pffo);
	pf_add_sign_diu(pffo);
}
