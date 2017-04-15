/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_add_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 13:14:57 by plefebvr          #+#    #+#             */
/*   Updated: 2016/11/23 17:16:19 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			pf_isupper0(char c)
{
	if (c > '0' && c <= '9')
		return (1);
	return (0);
}

void		pf_add_space_diu(t_pffo *pffo)
{
	int	i;

	i = 0;
	if (pffo->pst->data && pf_isupper0(pffo->pst->data[i]))
		pffo->pst->data = ft_strjoin_f2(" ", pffo->pst->data);
	else
	{
		while (pffo->pst->data[i] && !(ft_isdigit(pffo->pst->data[i])))
			i++;
		if (i > 0 && pffo->pst->data[i] && ft_isdigit(pffo->pst->data[i]))
			pffo->pst->data[i - 1] = ' ';
		else
			pffo->pst->data[0] = ' ';
	}
}

void		pf_add_negative_di(t_pffo *pffo)
{
	int	i;

	i = 0;
	if (pffo->pst->data && pf_isupper0(pffo->pst->data[i]))
		pffo->pst->data = ft_strjoin_f2("-", pffo->pst->data);
	else
	{
		while (pffo->pst->data[i] && !(ft_isdigit(pffo->pst->data[i])))
			i++;
		if (i > 0 && pffo->pst->data[i] && ft_isdigit(pffo->pst->data[i]))
			pffo->pst->data[i - 1] = '-';
		else
		{
			if (pf_nbrlen_str(pffo->pst->data) > pffo->precision)
				pffo->pst->data[0] = '-';
			else
				pffo->pst->data = ft_strjoin_f2("-", pffo->pst->data);
		}
	}
}

void		pf_add_positive_diu(t_pffo *pffo)
{
	int	i;

	i = 0;
	if (pffo->pst->data && pf_isupper0(pffo->pst->data[i]))
		pffo->pst->data = ft_strjoin_f2("+", pffo->pst->data);
	else if (pffo->pst->data && !(pf_isupper0(pffo->pst->data[i]))
				&& (pffo->flags && ft_strchr(pffo->flags, '-')))
	{
		pffo->pst->data = ft_strjoin_f2("+", pffo->pst->data);
	}
	else
	{
		while (pffo->pst->data[i] && !(ft_isdigit(pffo->pst->data[i])))
			i++;
		if (i > 0 && pffo->pst->data[i] && ft_isdigit(pffo->pst->data[i]))
			pffo->pst->data[i - 1] = '+';
		else
		{
			if (ft_strcmp(pffo->pst->data, "0") == 0)
				pffo->pst->data = ft_strjoin_f2("+", pffo->pst->data);
			else
				pffo->pst->data[0] = '+';
		}
	}
}

void		pf_add_sign_diu(t_pffo *pffo)
{
	int	i;

	i = 0;
	if (pffo->sign == '-')
		pf_add_negative_di(pffo);
	if (pffo->flags != NULL)
	{
		if (pffo->sign == '+' && ft_strchr(pffo->flags, '+'))
			pf_add_positive_diu(pffo);
		if (pffo->sign == '+' && ft_strchr(pffo->flags, ' ')
				&& !(ft_strchr(pffo->flags, '+')))
			pf_add_space_diu(pffo);
	}
}
