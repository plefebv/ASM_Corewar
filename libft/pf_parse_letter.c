/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_letter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 15:16:17 by plefebvr          #+#    #+#             */
/*   Updated: 2016/11/23 17:16:19 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void				pf_put_mfw2(t_pffo *pffo)
{
	if (pffo->minfield < 0)
	{
		pffo->minfield = -(pffo->minfield);
		if (pffo->flags)
			pffo->flags = ft_strjoin_f1(pffo->flags, "-");
		else
			pffo->flags = ft_strdup("-");
	}
}

static void			percentage(t_pffo *pffo, int *i, char c)
{
	(*i)++;
	pffo->letter = c;
	if (c == '%')
	{
		*i += 1;
		if (pffo->minfield)
			pf_put_in_pst(&pffo[0], ft_strdup(""));
	}
	else
		(*i)++;
}

static void			pf_special_letter2(t_pffo *pffo, char c)
{
	if (c == 'S')
	{
		pffo->letter = 's';
		if (pffo->length != NULL)
			free(pffo->length);
		pffo->length = ft_strdup("l");
	}
	if (c == 'C')
	{
		pffo->letter = 'c';
		if (pffo->length != NULL)
			free(pffo->length);
		pffo->length = ft_strdup("l");
	}
}

static void			pf_special_letter(t_pffo *pffo, char c)
{
	if (c == 'D')
	{
		pffo->letter = 'd';
		if (pffo->length != NULL)
			free(pffo->length);
		pffo->length = ft_strdup("l");
	}
	if (c == 'O')
	{
		pffo->letter = 'o';
		if (pffo->length != NULL)
			free(pffo->length);
		pffo->length = ft_strdup("l");
	}
	if (c == 'U')
	{
		pffo->letter = 'u';
		if (pffo->length != NULL)
			free(pffo->length);
		pffo->length = ft_strdup("l");
	}
	pf_special_letter2(pffo, c);
}

void				pf_put_letter(const char *fmt, int *i, t_pffo *pffo)
{
	char	c;

	c = fmt[*i + 1];
	if (c == '+' && (c = fmt[++(*i) + 1]))
		pffo->flags = pffo->flags ? ft_strjoin_f1(pffo->flags, "+")
			: ft_strdup("+");
	if (c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o'
			|| c == 'u' || c == 'x' || c == 'X'
			|| c == 'c' || c == '%')
		percentage(pffo, i, c);
	else if (c == 'D' || c == 'O' || c == 'U' || c == 'S' || c == 'C')
	{
		pf_special_letter(pffo, c);
		*i += 2;
	}
	else
	{
		pffo->letter = c;
		*i += fmt[*i + 1] == '\0' ? 1 : 2;
	}
}
