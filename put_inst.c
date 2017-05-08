/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_inst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 22:40:39 by plefebvr          #+#    #+#             */
/*   Updated: 2017/05/08 07:04:58 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"


static t_inst		*get_last_inst(t_env *env)
{
	t_inst	*tmp;

	tmp = env->inst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

static char			*get_inst_name(char **l)
{
	int		i = 0;
	char	*tmp;

	while (l[0][i] && ft_isalpha(l[0][i]))
		i++;
	tmp = ft_strsub(l[0], 0, i);
	l[0] = ft_strsub_f(l[0], i, ft_strlen(l[0]) - 1);
	l[0] = ft_strtrim_f(l[0]);
	ft_printf("GET_INST_NAME = %s\n LINE = |%s|\n", tmp, l[0]);
	return (tmp);
}

static char				**get_arg(char *l)
{
	char		**ret;
	int			i;

	i = 0;
	if (ft_strlen(l) <= 1)
		return (NULL);
	ret = ft_strsplit(l, SEPARATOR_CHAR);
	while (ret[i])
	{
		ft_printf("ARG[%d] = |%s|\n", i, ret[i]);
		ret[i] = ft_strtrim_f(ret[i]);
		ft_printf("ARG[%d] = |%s|\n", i, ret[i]);
		i++;
	}
	return (ret);
}

//static int			get_inst_size(t_inst *inst)
//static int			get_position(t_inst *inst)

void				put_inst(char *l, t_env *env)
{
	char		*trim;
	int			i = 0;
	t_inst		*inst;
//	t_op		op_tab;

	trim = ft_strtrim(l);
	inst = get_last_inst(env);
	if (!env->have_label)
	{
		inst->next = (t_inst *)ft_memalloc(sizeof(t_inst));
		inst = inst->next;
	}
	inst->instruction = get_inst_name(&trim);
	ft_printf("TRIMY LINE = |%s|\n", trim);
	inst->arg = get_arg(trim);
	/*	inst->size = get_inst_size(inst);
	inst->ocp = get_ocp(inst->instruction, inst->arg);
	inst->pos = get_position(env);*/
	inst->next = NULL;
	env->have_label = 0;
}
