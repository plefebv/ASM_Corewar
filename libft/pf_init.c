/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 19:19:05 by plefebvr          #+#    #+#             */
/*   Updated: 2016/11/23 17:16:19 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void		pf_init_pst(t_pffo *strct)
{
	t_pst	*pst;

	pst = (t_pst *)malloc(sizeof(t_pst));
	if (pst)
	{
		pst->data = NULL;
		pst->ret = 0;
		pst->mfw_n = 0;
		pst->next = NULL;
		strct->pst = pst;
		strct->pst_first = pst;
	}
}

void			pf_init_strct(t_pffo *strct)
{
	strct->flags = NULL;
	strct->minfield = 0;
	strct->star_minfield = 0;
	strct->true_precision = 0;
	strct->precision = 0;
	strct->star_precision = 0;
	strct->length = NULL;
	strct->letter = '?';
	strct->stars = 0;
	strct->ret = 0;
	strct->ret_tmp = 0;
	strct->ret_c = 0;
	strct->sign = '+';
	pf_init_pst(strct);
}
