/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_dioux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 19:57:48 by plefebvr          #+#    #+#             */
/*   Updated: 2016/11/23 15:52:33 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		pf_dioux(void *ap, t_pffo *pffo)
{
	if (pffo->letter == 'd' || pffo->letter == 'i')
		pf_di(ap, pffo);
	else if (pffo->letter == 'u')
		pf_u(ap, pffo);
	else if (pffo->letter == 'x' || pffo->letter == 'X' || pffo->letter == 'p')
		pf_hex(ap, pffo);
	else if (pffo->letter == 'o')
		pf_octal(ap, pffo);
}
