/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 23:53:04 by plefebvr          #+#    #+#             */
/*   Updated: 2017/05/12 02:50:41 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

/*
** reverse 4 bytes 11000110 00011111 00111111 11111100
*/
/*
unsigned int	ft_endian(unsigned int n)
{
		return ((n >> 24) | ((n & 0xff0000) >> 8) | ((n & 0xff00) << 8) |
						((n & 0xff) << 24));
}

** first convert n to 2 bytes length
** reverse 2 bytes 11000011 00110011


unsigned int	ft_endian(unsigned int n)
{
	n &= 0xffff;
	return ((n >> 8) | ((n & 0xff) << 8);
}
*/

static int		find_label(char *label, t_env *env)
{
	t_inst		*inst;
	t_label		*slabel;

	inst = env->inst;
	while (inst)
	{
		slabel = inst->label;
		while (slabel)
		{
			if (!(ft_strcmp(label, slabel->name)))
				return (1);
			slabel = slabel->next;
		}
		inst = inst->next;
	}
	return (0);
}

void			check_if_label_exist(t_env *env)
{
	t_inst		*inst;
	t_arg		*arg;

	inst = env->inst;
	while (inst)
	{
		arg = inst->arg;
		while (arg)
		{
			if (arg->is_label)
				(find_label(arg->label, env)) ? 0 : asm_error(12, env, arg->line);
			arg = arg->next;
		}
		inst = inst->next;
	}
}
