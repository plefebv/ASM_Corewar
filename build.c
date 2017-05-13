/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 23:39:37 by plefebvr          #+#    #+#             */
/*   Updated: 2017/05/13 09:17:41 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

void			print_everything(t_env *env)
{
	t_inst	*i;
	t_arg	*arg;
	t_label	*label;
	int		c = 0;

	if (!env)
		ft_printf("env null\n");
	else
	{
		ft_printf("env->header->name = %s\n\n", env->header->prog_name);
		ft_printf("env->header->comment = %s\n\n", env->header->comment);
		i = env->inst;
		while (i)
		{
			arg = i->arg;
			label = i->label;
			printf("INST = %s \n", i->instruction);
			while (label)
			{
				printf("label name = %s\n", label->name);
				label = label->next;
			}
			while (arg)
			{
				ft_printf("arg = |%s|", arg->name);
				if (arg->is_label)
					ft_printf(" | label = |%s|", arg->label);
				arg = arg->next;
				ft_putendl("");
			}
			ft_printf("total octal size = %d\n",  i->size);
			ft_printf("position = %d\n", i->pos);
			ft_printf("ocp = %8d\n", i->ocp);
			ft_printf("\n");
			c = 0;
			i = i->next;
		}
	}
}
