/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_syntax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 07:45:28 by plefebvr          #+#    #+#             */
/*   Updated: 2017/05/13 08:09:09 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

static void				process_valid_arg(char *arg, int *i, int dig)
{
	if (dig)
	{
		while (arg[*i] && ft_isdigit(arg[*i]))
			(*i)++;
	}
	else
	{
		while (arg[*i] && ft_isalnum(arg[*i]))
			(*i)++;
	}
}

void					arg_syntax_is_valid(char *arg, t_env *env)
{
	int		i;

	i = 0;
	while (arg[i] && arg[i] != ' ' && arg[i] != '\t' && arg[i] != '\n'
			&& arg[i] != '\v' && arg[i] != '\r' && arg[i] != '\f')
		i++;
	arg[i] ? asm_error(9, env, 0) : 0;
	i = 1;
	if (arg[0] && arg[0] == 'r')
		process_valid_arg(arg, &i, 1);
	else if (arg[0] && arg[0] == DIRECT_CHAR)
	{
		if (arg[1] && arg[1] == LABEL_CHAR)
		{
			i++;
			process_valid_arg(arg, &i, 0);
		}
		else
			process_valid_arg(arg, &i, 1);
	}
	else if (arg[0] && arg[0] != LABEL_CHAR)
		process_valid_arg(arg, &i, 1);
	else
		return ;
	arg[i] ? asm_error(9, env, 0) : 0;
}
