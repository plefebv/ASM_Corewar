/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_spe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 18:51:03 by plefebvr          #+#    #+#             */
/*   Updated: 2016/11/23 17:16:19 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char		*pf_strsub_spe(t_pffo *pffo, int add, unsigned long long i)
{
	char	*ret;

	i = 0;
	pffo->ret = ft_strlen(pffo->pst->data) + add + pffo->pst->mfw_n;
	ret = (char *)malloc(sizeof(char) * (pffo->ret + 1));
	if (ret)
	{
		while (i < pffo->ret)
		{
			ret[i] = pffo->pst->data[i];
			i++;
		}
		ret[i] = '\0';
		free(pffo->pst->data);
		return (ret);
	}
	else
		return (NULL);
}

static char	*part_one(t_pffo *pffo, char **str, int i)
{
	char	*ret;

	ret = NULL;
	if (i == 1)
	{
		if (*str)
			ret = pf_strjoin_c_null(*str, pffo, pffo->pst->mfw_n);
		pffo->ret += 1 + pffo->pst->mfw_n;
		pffo->pst->ret = pffo->pst->mfw_n == 0 ? 1 : 0;
		ft_memdel((void **)&(*str));
		return (ret);
	}
	if (i == 2)
	{
		if (*str)
			ret = pf_strjoin_c_null(*str, pffo, 0);
		pffo->ret += (1);
		pffo->pst->ret = 1;
		ft_memdel((void **)&(*str));
		return (ret);
	}
	return (NULL);
}

char		*pf_strjoin_spe(char *str, t_pffo *pffo, int add, int tmp)
{
	char					*ret;
	unsigned long long		i;
	unsigned long long		j;

	i = -1;
	j = 0;
	ret = NULL;
	tmp = ft_strlen(pffo->pst->data);
	if (pffo->pst->ret == 1 && pffo->pst->mfw_n)
		return (part_one(pffo, &str, 1));
	else if (pffo->pst->ret == 1 && !pffo->pst->mfw_n)
		return (part_one(pffo, &str, 2));
	else if (tmp > 0 && (pffo->ret += tmp))
	{
		if ((ret = (char *)malloc(sizeof(char) * (pffo->ret + 1))))
		{
			while (++i < pffo->ret - tmp - add)
				ret[i] = str[i];
			while (i + add < pffo->ret)
				ret[i++ + add] = pffo->pst->data[j++];
		}
		ft_memdel((void **)&str);
		return (ret);
	}
	return (str);
}
