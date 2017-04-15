/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_sc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 14:02:56 by plefebvr          #+#    #+#             */
/*   Updated: 2016/11/23 17:16:19 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void				pf_char_minfield(t_pffo *pffo, int left)
{
	char	*s;

	if ((s = (char *)ft_memalloc(sizeof(char) * pffo->minfield)))
	{
		s[pffo->minfield - 1] = '\0';
		if (!left)
		{
			if (pffo->flags && ft_strchr(pffo->flags, '0'))
				pf_add_char(&s, pffo->minfield - 1, '0');
			else
				pf_add_char(&s, pffo->minfield - 1, ' ');
			pffo->pst->data = ft_strjoin_f(s, pffo->pst->data);
		}
		else
		{
			pf_add_char(&s, pffo->minfield - 1, ' ');
			pffo->pst->data = ft_strjoin_f(pffo->pst->data, s);
		}
	}
}

static char			*pf_space_string(int size, t_pffo *pffo)
{
	char	*str;
	int		i;
	char	add;

	i = 0;
	add = (pffo->flags && ft_strchr(pffo->flags, '0')) ? '0' : ' ';
	if ((str = (char *)malloc(sizeof(char) * (size + 1))))
	{
		if (pffo->flags && ft_strchr(pffo->flags, '-'))
		{
			str[i++] = '\0';
			while (i < size + 1)
				str[i++] = add;
			pffo->pst->mfw_n = size;
			pffo->pst->ret = 1;
		}
		else
		{
			str[size] = '\0';
			while (i < size)
				str[i++] = add;
			pffo->pst->ret = 1;
		}
	}
	return (str);
}

static void			pf_treat_c(void *ap, t_pffo *pffo)
{
	if (pffo->letter == 'c')
	{
		pf_put_in_pst(pffo, ft_strdup(""));
		if (pffo->length && ft_strcmp("l", pffo->length) == 0)
		{
			if ((wchar_t)ap != 0)
				pf_put_wc((wchar_t)ap, pffo);
			if ((wchar_t)ap == 0 && !pffo->minfield)
			{
				pffo->pst->ret += 1;
			}
		}
		else
		{
			if ((char)ap != 0)
				pf_put_char((char)ap, pffo);
			if ((char)ap == 0 && !pffo->minfield)
				pffo->pst->ret += 1;
		}
	}
}

static void			pf_treat_s(void *ap, t_pffo *pffo)
{
	if (pffo->letter == 's')
	{
		if (pffo->length && ft_strcmp("l", pffo->length) == 0)
		{
			if ((wchar_t *)ap != NULL)
				pf_put_ws(ap, pffo);
			else
				pf_put_in_pst(pffo, ft_strdup("(null)"));
		}
		else
		{
			if ((char *)ap != NULL)
				pf_put_in_pst(pffo, ft_strdup((char *)ap));
			else
				pf_put_in_pst(pffo, ft_strdup("(null)"));
		}
		pf_precision_s(pffo);
		pf_minfield(pffo);
	}
}

void				pf_sc(void *ap, t_pffo *pffo)
{
	pf_treat_c(ap, pffo);
	pf_treat_s(ap, pffo);
	if (!(pffo->letter == 'c' && (char)ap == 0))
		pf_treat_data(pffo);
	else if (pffo->letter == 'c' && (char)ap == 0 && pffo->minfield > 0)
	{
		pf_put_in_pst(pffo, ft_strdup(""));
		free(pffo->pst->data);
		pffo->pst->data = pf_space_string(pffo->minfield - 1, pffo);
	}
}
