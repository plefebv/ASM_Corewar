/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 17:49:13 by plefebvr          #+#    #+#             */
/*   Updated: 2017/05/14 19:31:46 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

int		main(int ac, char **av)
{
	t_env	*env;

	env = NULL;
	if (ac == 1)
		asm_error(0, NULL, 0);
	env = parse_s_file(av[ac - 1]);
	generate_file(env);
	free_env(env);
	return (0);
}
