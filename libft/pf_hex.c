/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 14:16:04 by plefebvr          #+#    #+#             */
/*   Updated: 2016/11/23 17:16:19 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int			pf_hex_len(unsigned long long n)
{
	unsigned long long		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n >= 16)
	{
		n = n >> 4;
		i++;
	}
	return (i);
}

static char			pf_get_hex(t_pffo *pffo, unsigned long long n)
{
	unsigned long long	i;

	i = n & 15;
	if (i < 10)
		return (48 + i);
	else if (pffo->letter == 'X')
		return (55 + i);
	else if (pffo->letter == 'x' || pffo->letter == 'p')
		return (87 + i);
	else
		return (0);
}

static char			*pf_itoa_hex(unsigned long long n, t_pffo *pffo)
{
	char		*str;
	long long	i;

	i = pf_hex_len(n);
	str = ft_strnew(i + 1);
	if (str)
	{
		if (n == 0)
			str[0] = '0';
		while (n > 0)
		{
			str[i--] = pf_get_hex(pffo, n);
			n >>= 4;
		}
		return (str);
	}
	return (NULL);
}

static void			pf_hex_length(void *ap, t_pffo *pffo)
{
	if (ft_strcmp("hh", pffo->length) == 0)
		pf_put_in_pst(pffo, pf_itoa_hex((unsigned char)ap, pffo));
	if (ft_strcmp("h", pffo->length) == 0)
		pf_put_in_pst(pffo, pf_itoa_hex((unsigned short)ap, pffo));
	if (ft_strcmp("l", pffo->length) == 0)
		pf_put_in_pst(pffo, pf_itoa_hex((unsigned long)ap, pffo));
	if (ft_strcmp("ll", pffo->length) == 0)
		pf_put_in_pst(pffo, pf_itoa_hex((unsigned long long)ap, pffo));
	if (ft_strcmp("j", pffo->length) == 0)
		pf_put_in_pst(pffo, pf_itoa_hex((uintmax_t)ap, pffo));
	if (ft_strcmp("z", pffo->length) == 0)
		pf_put_in_pst(pffo, pf_itoa_hex((size_t)ap, pffo));
}

void				pf_hex(void *ap, t_pffo *pffo)
{
	int		i;

	i = 2;
	if (pffo->letter == 'p')
		pffo->length = ft_strdup("j");
	pffo->length ? pf_hex_length(ap, pffo) :
		pf_put_in_pst(pffo, pf_itoa_hex((unsigned)ap, pffo));
	pf_hex2(ap, pffo);
	if (pffo->flags && ft_strchr(pffo->flags, '#') && pffo->pst->data
				&& ft_strlen(pffo->pst->data) > 1 && pffo->pst->data[0] != ' ')
	{
		pffo->pst->data[1] = pffo->letter == 'X' ? 'X' : 'x';
		while (pffo->pst->data[i] != '\0'
				&& pffo->pst->data[i] != (pffo->letter == 'X' ? 'X' : 'x'))
			i++;
		if (pffo->pst->data[i] == 'X' || pffo->pst->data[i] == 'x')
			pffo->pst->data[i] = '0';
	}
	if (pffo->true_precision && !pffo->precision && pffo->minfield == 0
			&& (unsigned)ap == 0 && pffo->letter != 'p')
		pffo->pst->data[0] = '\0';
}
