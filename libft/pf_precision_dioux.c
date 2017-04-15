/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_precision_dioux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 16:40:25 by plefebvr          #+#    #+#             */
/*   Updated: 2016/11/23 17:16:19 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		pf_add_char(char **s, int add, char c)
{
	int		i;

	i = 0;
	while (i < add)
		s[0][i++] = c;
}

void		pf_add_precision_dioux(t_pffo *pffo, int add)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * (add + 1));
	if (s)
	{
		s[add] = '\0';
		pf_add_char(&s, add, '0');
		pffo->pst->data = ft_strjoin_f(s, pffo->pst->data);
	}
}

void		pf_precision_dioux(void *ap, t_pffo *pffo)
{
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(pffo->pst->data);
	if (size < pffo->precision)
		pf_add_precision_dioux(pffo, pffo->precision - size);
	if (!pffo->precision && (int)ap == 0)
	{
		while (pffo->pst->data && pffo->pst->data[i] != '\0')
		{
			if (pffo->pst->data[i] == '0')
			{
				if (pffo->minfield > 0)
					pffo->pst->data[i] = ' ';
				else
					pffo->pst->data[i] = '\0';
			}
			i++;
		}
	}
}

void		pf_precision_p(void *ap, t_pffo *pffo)
{
	int		size;
	int		i;

	i = -1;
	size = ft_strlen(pffo->pst->data);
	if (size < pffo->precision + 2)
		pf_add_precision_dioux(pffo, pffo->precision - size + 2);
	if (!pffo->precision && (int)ap == 0)
	{
		while (pffo->pst->data && pffo->pst->data[++i] != '\0')
		{
			if (pffo->pst->data[i] == '0')
			{
				if (pffo->minfield > 0)
					pffo->pst->data[i] = ' ';
				else
					pffo->pst->data[i] = '\0';
			}
		}
	}
	i = 1;
	pffo->pst->data[1] = 'x';
	while (pffo->pst->data[++i])
		if (pffo->pst->data[i] == 'x')
			pffo->pst->data[i] = '0';
}
