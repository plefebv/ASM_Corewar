/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 07:40:46 by plefebvr          #+#    #+#             */
/*   Updated: 2017/05/13 07:42:28 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

static int				is_label(char *name)
{
	if (name[0] && name[0] == LABEL_CHAR)
		return (1);
	if (name[0] && name[0] == DIRECT_CHAR && name[1] && name[1] == LABEL_CHAR)
		return (1);
	else
		return (0);
}

static char				*grep_label(char *name, t_env *env)
{
	int			i;
	int			j;
	int			direct;
	int			label;

	direct = 0;
	label = 0;
	i = 0;
	j = 0;
	while (name[i])
	{
		if (name[i] == DIRECT_CHAR)
		{
			j++;
			direct++;
		}
		if (name[i] == LABEL_CHAR)
		{
			j++;
			label++;
		}
		i++;
	}
	if (!label || label > 1 || direct > 1)
		asm_error(11, env, 0);
	return (ft_strsub(name, j, ft_strlen(name) - j));
}

static int			get_arg_size(char *arg, t_op *op)
{
	if (arg[0] == 'r')
		return (1);
	else if (arg[0] == DIRECT_CHAR)
		return (op->label_size);
	else
		return (2);
}

static void				add_arg(t_inst *inst, char *arg, t_op *op, t_env *env)
{
	t_arg		*tmp;

	tmp = inst->arg;
	if (!tmp)
	{
		inst->arg = (t_arg *)ft_memalloc(sizeof(t_arg));
		!(inst->arg) ? malloc_error(0) : 0;
		tmp = inst->arg;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_arg *)ft_memalloc(sizeof(t_arg));
		tmp = tmp->next;
		!(tmp) ? malloc_error(0) : 0;
	}
	tmp->name = ft_strdup(arg);
	tmp->size = get_arg_size(arg, op);
	tmp->is_label = is_label(tmp->name);
	tmp->label = tmp->is_label ? grep_label(tmp->name, env) : NULL;
	tmp->line = env->nb_l;
}

void			get_arg(char *l, t_inst *inst, t_env *env)
{
	char		**ret;
	int			i;
	t_op		*op;

	op = get_optab(inst->instruction);
	i = 0;
	if (ft_strlen(l) <= 1)
		return ;
	ret = ft_strsplit(l, SEPARATOR_CHAR);
	while (ret[i])
	{
		ret[i] = ft_strtrim_f(ret[i]);
		arg_syntax_is_valid(ret[i], env);
		add_arg(inst, ret[i], op, env);
		i++;
	}
	//free ret;
}

