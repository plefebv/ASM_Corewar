/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_inst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 22:40:39 by plefebvr          #+#    #+#             */
/*   Updated: 2017/05/06 06:16:50 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"


static t_inst		*get_last_inst(t_env *env)
{
	int		i;
	t_inst	*tmp;

	i = 0;
	tmp = env->inst;
	while (tmp->inst->next)
		tmp->inst = tmp->inst->next;
	return (tmp);
}

static char			*get_inst_name(char *l)
{
	int		i;

	i = 0;
	while (l[i] && ft_isalpha(l[i]))
		i++;


}
//static char			**get_arg(char *l)
//static int			get_inst_size(t_inst *inst)
//static int			get_position(t_inst *inst)

void				put_inst(char *l, t_env *env)
{
	char		*trim;
	int			i;
	t_inst		*inst;
	t_op		op_tab;

	trim = ft_strtrim(l);
	if (env->have_label)
		inst = get_last_int(t_env *env);
	else
		inst = (t_inst *)ft_memalloc(sizeof(t_inst));
	inst->instruction = get_inst_name(l);
	inst->arg = get_arg(l);
	inst->size = get_inst_size(inst);
	inst->ocp = get_ocp(inst->instruction, inst->arg);
	inst->pos = get_position(env);
	inst->next = NULL;
	env->have_label = 0;
}
