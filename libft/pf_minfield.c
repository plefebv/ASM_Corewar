/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_minfield.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 12:41:15 by plefebvr          #+#    #+#             */
/*   Updated: 2016/11/23 17:16:19 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		pf_add_minfield_l(t_pffo *pffo, int add, char c)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * (add + 1));
	if (s)
	{
		s[add] = '\0';
		if (pffo->letter != 'u')
		{
			if (pffo->sign == '-' || (pffo->flags && pffo->sign == '+' &&
				(ft_strchr(pffo->flags, ' ') || ft_strchr(pffo->flags, '+'))))
				add--;
		}
		pf_add_char(&s, add, c);
		pffo->pst->data = ft_strjoin_f(pffo->pst->data, s);
	}
}

void		pf_add_minfield_r(t_pffo *pffo, int add, char c)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * (add + 1));
	if (s)
	{
		s[add] = '\0';
		pf_add_char(&s, add, c);
		pffo->pst->data = ft_strjoin_f(s, pffo->pst->data);
	}
}

void		pf_minfield(t_pffo *pffo)
{
	int		size;

	size = ft_strlen(pffo->pst->data);
	if (size < pffo->minfield)
	{
		size = pffo->minfield - size;
		if ((pffo->flags && ft_strchr(pffo->flags, '-')
					&& pffo->letter != 'p') ||
					(pffo->letter == 'p' && pffo->flags &&
					ft_strchr(pffo->flags, '0')
					&& !(ft_strcmp(pffo->pst->data, "0x0"))))
			pf_add_minfield_l(pffo, size, pffo->letter == 'p' ? '0' : ' ');
		else if (pffo->flags && ft_strchr(pffo->flags, '-')
					&& pffo->letter == 'p')
			pf_add_minfield_l(pffo, size, ' ');
		else if (pffo->flags && ft_strchr(pffo->flags, '0') &&
					(((!pffo->true_precision || pffo->precision < 0)
					&& pffo->letter != 's')
					|| (pffo->letter == 'c' || pffo->letter == 's')))
			pf_add_minfield_r(pffo, size, '0');
		else
			pf_add_minfield_r(pffo, size, ' ');
	}
}
