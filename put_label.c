/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 18:22:58 by plefebvr          #+#    #+#             */
/*   Updated: 2017/05/08 05:50:03 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

static void		new_inst_label(t_env *env, char *name)
{
	t_inst		*new;
	t_inst		*tmp;

	tmp = env->inst;
	new = (t_inst *)ft_memalloc(sizeof(t_inst));
	new->label = (t_label *)ft_memalloc(sizeof(t_label));
	if (!new || !new->label)
		malloc_error(0);
	new->label->name = ft_strdup(name);
	new->label->original = 1;
	new->label->next = NULL;
	if (!tmp)
	{
		env->inst = new;
		ft_printf("NEW \n env->inst->label->name = %s\n", env->inst->label->name);
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		ft_printf("ADD \n env->inst->label->name = %s\n", tmp->next->label->name);
	}
}
 
static void		add_label_to_label(char *l, t_env *env)
{
	t_inst	*tmp;
	t_label *l_tmp;

	tmp = env->inst;
	l_tmp = NULL;
	while(tmp->next)
		tmp = tmp->next;
	l_tmp = tmp->label;
	while (l_tmp->next)
		l_tmp = l_tmp->next;
	l_tmp->next = (t_label *)ft_memalloc(sizeof(t_label));
	if (!l_tmp->next)
		malloc_error(0);
	else
	{
		l_tmp->next->name = ft_strdup(l);
		ft_printf("ADD LABEL = %s\n", l_tmp->next->name);
	}	
}

static int		check_if_inst(char *l)
{
	char *t;
	int ret;

	t = ft_strtrim(l);
	ft_printf("t = |%s|\n", t);
	ret = get_opcode(t);
	if (ret == -1)
		return (0);
	return (ret);
}

void			put_label(char *l, t_env *env)
{
	int		i;
	char 	*t;
	char	*tmp;

	i = 0;
	tmp = NULL;
	t = ft_strtrim(l);
	while (t[i] && t[i] != LABEL_CHAR)
		i++;
	tmp = ft_strsub(t, 0, i);
	if (env->have_label == 0)
		new_inst_label(env, tmp);
	else if (env->have_label)
		add_label_to_label(tmp, env);
	env->have_label++;
	ft_memdel((void **)&tmp);
	tmp = ft_strsub(t, i + 1, ft_strlen(t));
	if (check_if_inst(tmp))
	{
		put_inst(tmp, env);
		env->have_label = 0;
	}
	ft_memdel((void **)&tmp);
}
