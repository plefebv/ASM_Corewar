/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 13:23:00 by plefebvr          #+#    #+#             */
/*   Updated: 2017/05/14 19:17:37 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

static void		write_r(int fd, char *r, t_arg *arg)
{
	int			i;
	char c;

	i = 0;
	while (!(ft_isdigit(r[i])))
			i++;
	c = (char)ft_atoi(r + i);
	if (c <= 0 || c > REG_NUMBER)
		return (asm_error(17, NULL, arg->line));
	write(fd, &c, 1);
}

static int		find_label_pos(char *search, t_env *env, t_arg *arg)
{
	t_inst	*inst;
	t_label	*lab;

	inst = env->inst;
	while (inst)
	{
		lab = inst->label;
		while (lab)
		{
			if (!(ft_strcmp(search, lab->name)))
				return (inst->pos);
			lab = lab->next;
		}
		inst = inst->next;
	}
	asm_error(12, NULL, arg->line);
	return (42);
}

static void		putrevcpy(int fd, char *src, int size)
{
		while (size--)
			write(fd, src + size, 1);
}

static void		write_dir(int fd, t_arg *arg, t_env *env, t_inst *inst)
{
	int		ret;
	
	if (arg->is_label)
	{
		ret = find_label_pos(arg->label, env, arg) - inst->pos;
		putrevcpy(fd, (char *)&ret, arg->size);
	}
	else
	{
		ret = ft_atoi(arg->name + 1);
		putrevcpy(fd, (char *)&ret, arg->size);
	}
}

static void		write_ind(int fd, t_arg *arg, t_env *env, t_inst *inst)
{
	int	ret;

	if (arg->is_label)
	{
		ret = find_label_pos(arg->label, env, arg) - inst->pos;
		putrevcpy(fd, (char *)&ret, 2);
	}
	else
	{
		ret = ft_atoi(arg->name);
		putrevcpy(fd, (char *)&ret, 2);
	}
}

static void		write_arg(int fd, t_arg *arg, t_env *env, t_inst *inst)
{
	t_arg	*tmp;
	
	tmp = arg;
	while (tmp)
	{
		if (tmp->t == 1) 
				write_r(fd, tmp->name, tmp);
		else if (tmp->t == 2) 
			write_dir(fd, tmp, env, inst);
		else if (tmp->t == 4)
			write_ind(fd, tmp, env, inst);
		tmp = tmp->next;
	}
}

void			write_instruction(int fd, t_env *env)
{
	t_inst		*inst;
	t_op		*op;

	inst = env->inst;
	while (inst)
	{
		if (inst->instruction)
		{
			op = get_optab(inst->instruction);
			write(fd, &(op->opcode), 1);
			if (inst->ocp != -1)
				write(fd, &(inst->ocp), 1);
			if (inst->arg)
				write_arg(fd, inst->arg, env, inst);
		}
		inst = inst->next;
	}
}