/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 17:49:13 by plefebvr          #+#    #+#             */
/*   Updated: 2017/04/18 19:45:19 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

int		main(int ac, char **av)
{
	//t_env	*env;

	//env = (t_env **)ft_memalloc(sizeof(t_env *));
	//init(&env);
	if (ac == 1)
		asm_error(0);
	ft_printf("av[1] = %s\n", av[1]);
	parse_s_file(av[ac - 1]);
	return (0);
}
