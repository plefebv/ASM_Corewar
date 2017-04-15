/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_pst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 12:40:04 by plefebvr          #+#    #+#             */
/*   Updated: 2016/11/23 17:16:19 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_pst		*pf_create_link(char *input)
{
	t_pst		*ret;

	ret = (t_pst*)malloc(sizeof(t_pst));
	if (ret)
	{
		ret->data = ft_strdup_f(input);
		ret->ret = 0;
		ret->mfw_n = 0;
		ret->next = NULL;
	}
	return (ret);
}

void		pf_put_in_pst(t_pffo *pffo, char *input)
{
	if (pffo->pst_first->data == NULL)
	{
		pffo->pst->data = ft_strdup_f(input);
		pffo->pst_first = pffo->pst;
	}
	else
	{
		while (pffo->pst->next)
			pffo->pst = pffo->pst->next;
		pffo->pst->next = pf_create_link(input);
		pffo->pst = pffo->pst->next;
	}
}

static void	join_process(t_pffo *pffo, char **str, unsigned long long *miaou)
{
	t_pst		*tmp;
	int			i;

	i = 0;
	tmp = NULL;
	while (pffo->pst)
	{
		if (*str == NULL)
			*str = pf_strsub_spe(pffo, pffo->pst->ret, 0);
		else if (!(!pffo->pst->data || (!ft_strlen(pffo->pst->data) \
						&& !pffo->pst->mfw_n)) || pffo->pst->ret)
		{
			miaou[0] = pffo->ret;
			*str = pf_strjoin_spe(*str, pffo, i, 0);
			miaou[0] == pffo->ret ? *miaou = pffo->ret : free(pffo->pst->data);
		}
		i = pffo->pst->ret;
		tmp = pffo->pst;
		pffo->pst = pffo->pst->next;
		ft_memdel((void **)&tmp);
	}
}

int			pf_print_list(t_pffo *pffo)
{
	unsigned long long		miaou;
	char					*str;

	miaou = 0;
	pffo->pst = pffo->pst_first;
	str = NULL;
	if (!pffo->pst->data)
		return (0);
	else if (!pffo->pst_first)
	{
		ft_putstr("0\n");
		return (0);
	}
	join_process(pffo, &str, &miaou);
	ft_memdel((void **)&pffo->pst);
	miaou = pffo->ret;
	if (pffo->ret > 0)
		write(1, str, pffo->ret);
	ft_memdel((void **)&str);
	ft_memdel((void **)&pffo[0]);
	return (miaou);
}
