/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 18:22:58 by plefebvr          #+#    #+#             */
/*   Updated: 2017/04/28 18:54:22 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

static void		new_inst_label(t_env *env, char *name)
{
	t_inst		*new;
	t_inst		*tmp;

	tmp = env->inst;
	new = (t_inst *)ft_memalloc(sizeof(t_inst));
	if (!new)
		malloc_error(0);
	new->label = ft_strdup(name);
	if (!tmp)
		env->inst = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
 
static void		add_label_to_label(char *l, t_env *env)
{
	t_inst	*tmp;

	tmp = env->inst;
	if (!tmp)
		test_error(0);
	else
	{
		while(tmp->next)
			tmp = tmp->next;
		tmp->label = ft_strjoin(tmp->label, "\n");
		tmp->label = ft_strjoin(tmp->label, l);
	}
}

static int		check_if_inst(char *l)
{
	l = ft_strtrim(tmp);
	
	ret = get_opcode(l);
	if (ret == -1)
		return (0);
	return (ret);
}
char			*put_label(char *l, t_env *env)
{
	int		i;
	char 	*t;
	char	*tmp;

	i = 0;
	tmp = NULL;
	t = ft_strstrim(l);
	while (t[i] && t[i] != LABEL_CHAR)
		i++;
	tmp = ft_strsub(t, 0, i);
	if (env->have_label == 0)
		new_inst_label(env, tmp);
	if (env->have_label)
		add_label_to_label(env, tmp);
	env->have_label++;
	ft_memdel((void **)&tmp);
	tmp = ft_strsub(t, i, ft_strlen(t));
	if (check_if_inst(tmp))
	{
		put_inst(tmp, env);
		env->have_label = 0;
	}
	ft_memdel((void **)&tmp);
}
