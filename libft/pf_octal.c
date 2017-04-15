/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 16:12:34 by plefebvr          #+#    #+#             */
/*   Updated: 2016/11/23 17:16:19 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int		pf_octal_len(unsigned long long n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n >= 8)
	{
		n = n / 8;
		i++;
	}
	return (i);
}

static char		*pf_itoa_octal(unsigned long long n)
{
	char		*str;
	long long	i;

	i = pf_octal_len(n);
	str = ft_strnew(i + 1);
	if (str)
	{
		if (n == 0)
			str[0] = '0';
		while (n > 0)
		{
			str[i--] = (n % 8) + 48;
			n /= 8;
		}
		return (str);
	}
	return (NULL);
}

static void		pf_octal_length(void *ap, t_pffo *pffo)
{
	if (ft_strcmp("hh", pffo->length) == 0)
		pf_put_in_pst(pffo, pf_itoa_octal((unsigned char)ap));
	if (ft_strcmp("h", pffo->length) == 0)
		pf_put_in_pst(pffo, pf_itoa_octal((unsigned short)ap));
	if (ft_strcmp("l", pffo->length) == 0)
		pf_put_in_pst(pffo, pf_itoa_octal((unsigned long)ap));
	if (ft_strcmp("ll", pffo->length) == 0)
		pf_put_in_pst(pffo, pf_itoa_octal((unsigned long long)ap));
	if (ft_strcmp("j", pffo->length) == 0)
		pf_put_in_pst(pffo, pf_itoa_octal((uintmax_t)ap));
	if (ft_strcmp("z", pffo->length) == 0)
		pf_put_in_pst(pffo, pf_itoa_octal((size_t)ap));
}

void			pf_octal(void *ap, t_pffo *pffo)
{
	int		i;

	i = 0;
	pffo->length ? pf_octal_length(ap, pffo) :
		pf_put_in_pst(pffo, pf_itoa_octal((unsigned)ap));
	if (pffo->flags && ft_strchr(pffo->flags, '#') && pffo->pst->data[0] != '0')
		pffo->pst->data = ft_strjoin_f2("0", pffo->pst->data);
	if (pffo->true_precision && pffo->precision && (int)ap != 0)
		pf_precision_dioux(ap, pffo);
	if (pffo->true_precision && !pffo->precision && (int)ap == 0)
	{
		free(pffo->pst->data);
		if (pffo->flags && ft_strchr(pffo->flags, '#'))
			pffo->pst->data = ft_strdup("0");
		else
			pffo->pst->data = ft_strdup("");
	}
	if (pffo->minfield > 0)
		pf_minfield(pffo);
}
