/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 17:49:13 by plefebvr          #+#    #+#             */
/*   Updated: 2017/05/12 00:15:18 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

int		main(int ac, char **av)
{
	t_env	*env;
//	t_inst 	*i;
//	int		c = 0;

	env = NULL;
	if (ac == 1)
		asm_error(0, NULL, 0);
	ft_printf("av[1] = %s\n", av[1]);
	env = parse_s_file(av[ac - 1]);
	generate_file(env);
	return (0);
}
