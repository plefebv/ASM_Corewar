/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 10:11:56 by plefebvr          #+#    #+#             */
/*   Updated: 2017/05/13 11:54:16 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

/*static void		grap_valid_arg(int	**valid, t_op *op)
{
	int		i;

	i = 0;
	while (i < op->nb_arg)
	{
		valid[i] = op->nb_arg[i];
		i++;
	}
}*/

void			check_arg_type(t_inst *inst, t_op *op, t_env *env)
{
	t_arg	*a;
	int		i;

	i = 0;
	a = inst->arg;
	if (inst)
	{
		ft_printf("INST = %s\n", inst->instruction);
		while(a && i < op->nb_arg)
		{
			if (op->arg[i] == 1)
				a->t == 1 ? 0 : asm_error(16, env, a->line);
			if (op->arg[i] == 2)
				a->t == 2 ? 0 : asm_error(16, env, a->line);
			if (op->arg[i] == 3)
				a->t == 1 || a->t == 2 ? 0 : asm_error(16, env, a->line);
			if (op->arg[i] == 4)
				a->t == 4 ? 0 : asm_error(16, env, a->line);
			if (op->arg[i] == 5)
				a->t == 1 || a->t == 4 ? 0 : asm_error(16, env, a->line);
			if (op->arg[i] == 6)
				a->t == 2 || a->t == 4 ? 0 : asm_error(16, env, a->line);
			if (op->arg[i] == 7)
				a->t == 1 || a->t == 2 || a->t == 4 ? 0 : asm_error(16, env, a->line);
			a = a->next;
			i++;
		}
		i = 0;
	}
}
