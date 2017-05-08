/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 17:49:13 by plefebvr          #+#    #+#             */
/*   Updated: 2017/05/08 05:18:25 by plefebvr         ###   ########.fr       */
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
	env = parse_s_file(av[ac - 1]);
	if (!env)
		ft_printf("env null\n");
	else
	{
		ft_printf("env->name = %s\n", env->name);
		i = env->inst;
		ft_printf("seg1\n");
		l = i->label;
		while (i)
		{
			printf("INST\n");
			while (i->label)
			{
				printf("l->name = %s\n", i->label->name);
				i->label = i->label->next;
			}
			ft_printf("\n");
			i = i->next;
		}
	}
	return (0);
}
