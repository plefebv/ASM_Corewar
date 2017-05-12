/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_inst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 22:40:39 by plefebvr          #+#    #+#             */
/*   Updated: 2017/05/12 03:24:54 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"


static int			get_position(t_env *env)
{
	int		pos;
	t_inst	*tmp;

	pos = 0;
	tmp = env->inst;
	while (tmp->next)
	{
		pos += tmp->size;
		tmp = tmp->next;
	}
	return (pos);
}

static int			get_ocp(char *inst, t_arg *arg)
{
	t_op	*op;
	char	*ret;
	t_arg	*tmp;
	int		i;

	tmp = arg;
	op = get_optab(inst);
	if (op && op->need_oc == 0)
		return (-1);
	ret = ft_strdup("");
	while (tmp)
	{
		if (tmp->name[0] == 'r')
			ret = ft_strjoin_f1(ret, "01");
		else if (tmp->name[0] == DIRECT_CHAR)
			ret = ft_strjoin_f1(ret, "10");
		else
			ret = ft_strjoin_f1(ret, "11");
		tmp = tmp->next;
	}
	while (ft_strlen(ret) != 8)
		ret = ft_strjoin_f1(ret, "00");
	i = ft_atoi_base(ret, 2);
	ft_memdel((void **)&ret);
	return (i);
}

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
	return (tmp);
}

static void				process_valid_arg(char *arg, int *i, int dig)
{
	if (dig)
	{
		while (arg[*i] && ft_isdigit(arg[*i]))
			(*i)++;
	}
	else
	{
		while (arg[*i] && ft_isalnum(arg[*i]))
			(*i)++;
	}
}

static void				arg_syntax_is_valid(char *arg, t_env *env)
{
	int		i;

	i = 0;
	while (arg[i] && arg[i] != ' ' && arg[i] != '\t' && arg[i] != '\n'
			&& arg[i] != '\v' && arg[i] != '\r' && arg[i] != '\f')
		i++;
	arg[i] ? asm_error(9, env, 0) : 0;
	i = 1;
	if (arg[0] && arg[0] == 'r')
		process_valid_arg(arg, &i, 1);
	else if (arg[0] && arg[0] == DIRECT_CHAR)
	{
		if (arg[1] && arg[1] == LABEL_CHAR)
		{
			i++;
			process_valid_arg(arg, &i, 0);
		}
		else
			process_valid_arg(arg, &i, 1);
	}
	else if (arg[0] && arg[0] != LABEL_CHAR)	
			process_valid_arg(arg, &i, 1);
	else
		return ;
	arg[i] ? asm_error(9, env, 0) : 0;
}

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
	int			percentage;
	int			double_dot;

	percentage = 0;
	double_dot = 0;
	i = 0;
	j = 0;
	while (name[i])
	{
		if (name[i] == DIRECT_CHAR)
		{
			j++;
			percentage++;
		}
		if (name[i] == LABEL_CHAR)
		{
			j++;
			double_dot++;
		}
		i++;
	}
	if (!double_dot || double_dot > 1 || percentage > 1)
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

static void			get_arg(char *l, t_inst *inst, t_env *env)
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

static int			get_inst_size(t_inst *inst, t_env *env)
{
	int		i;
	t_op	*op;
	int		ret;
	t_arg	*arg;

	i = 0;
	ret = 1;
	if (inst->arg == NULL)
	{
		return (0);
	}	
	arg = inst->arg;
	op = get_optab(inst->instruction);
	ret += op->need_oc;
	while (arg)
	{
		ret += arg->size;
		arg = arg->next;
		i++;
	}
	if (i != op->nb_arg)
		asm_error(8, env, 0);
	return (ret);
}

void				put_inst(char *l, t_env *env)
{
	char		*trim;
	t_inst		*inst;

	trim = ft_strtrim(l);
	inst = get_last_inst(env);
	if (!env->have_label)
	{
		inst->next = (t_inst *)ft_memalloc(sizeof(t_inst));
		inst = inst->next;
		inst->instruction = NULL;
		inst->arg = NULL;
	}
	inst->instruction = get_inst_name(&trim);
	get_arg(trim, inst, env);
	inst->size = get_inst_size(inst, env);
	inst->ocp = get_ocp(inst->instruction, inst->arg);
	inst->pos = get_position(env);
	inst->next = NULL;
	env->have_label = 0;
}
