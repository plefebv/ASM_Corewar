/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 13:04:59 by plefebvr          #+#    #+#             */
/*   Updated: 2016/11/23 17:16:19 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void		pf_u_length(void *ap, t_pffo *pffo)
{
	if (ft_strcmp("hh", pffo->length) == 0)
		pf_put_in_pst(pffo, pf_itoa_ull((unsigned char)ap));
	if (ft_strcmp("h", pffo->length) == 0)
		pf_put_in_pst(pffo, pf_itoa_ull((unsigned short)ap));
	if (ft_strcmp("l", pffo->length) == 0)
		pf_put_in_pst(pffo, pf_itoa_ull((unsigned long)ap));
	if (ft_strcmp("ll", pffo->length) == 0)
		pf_put_in_pst(pffo, pf_itoa_ull((unsigned long long)ap));
	if (ft_strcmp("j", pffo->length) == 0)
		pf_put_in_pst(pffo, pf_itoa_ull((uintmax_t)ap));
	if (ft_strcmp("z", pffo->length) == 0)
		pf_put_in_pst(pffo, pf_itoa_ull((size_t)ap));
}

void			pf_u(void *ap, t_pffo *pffo)
{
	int		i;

	i = 0;
	pffo->length ? pf_u_length(ap, pffo) :
		pf_put_in_pst(pffo, pf_itoa_ull((unsigned)ap));
	if (pffo->true_precision)
		pf_precision_dioux(ap, pffo);
	if (pffo->minfield > 0)
		pf_minfield(pffo);
}
