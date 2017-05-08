/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 17:49:13 by plefebvr          #+#    #+#             */
/*   Updated: 2017/05/08 04:38:31 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

int		main(int ac, char **av)
{
	t_env	*env;
	t_inst 	*i;
	t_label *l;

	//env = (t_env **)ft_memalloc(sizeof(t_env *));
	//init(&env);
	env = NULL;
	if (ac == 1)
		asm_error(0, -1);
	ft_printf("av[1] = %s\n", av[1]);
	parse_s_file(av[ac - 1], env);
	ft_printf("env->name = %s\n", env->name);
	//i = env->inst;
	ft_printf("seg1\n");
	//l = env->inst->label;
	while (env->inst)
	{
		printf("INST\n");
		while (l)
		{
			printf("l->name = %s\n", l->name);
			l = l->next;
		}
		env->inst = env->inst->next;
	}
	return (0);
}
