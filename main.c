/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 17:49:13 by plefebvr          #+#    #+#             */
/*   Updated: 2017/05/08 07:30:12 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

int		main(int ac, char **av)
{
	t_env	*env;
	t_inst 	*i;
	int		c = 0;

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
		while (i)
		{
			printf("INST = %s \n", i->instruction);
			while (i->label)
			{
				printf("label name = %s\n", i->label->name);
				i->label = i->label->next;
			}
			while (i->arg[c])
			{
				ft_printf("arg = |%s|\n", i->arg[c]);
				c++;
			}
			ft_printf("total octal size = %d\n",  i->size);
			ft_printf("\n");
			c = 0;
			i = i->next;
		}
	}
	return (0);
}
