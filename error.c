/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 17:51:42 by plefebvr          #+#    #+#             */
/*   Updated: 2017/05/13 10:00:58 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

void			test_error(int e)
{
	ft_printf("Test error n*%d\n", e);
	exit(e);
}

/*
** NE PAS OUBLIER DE FREE ENV AVANT EXIT()
*/

void			asm_error(int e, t_env *env, int l)
{
	!e ? ft_printf("Put at least one s file in argument") : 0;
	e == 1 ? ft_printf("The file must be a .s") : 0;
	e == 2 ? ft_printf("Bad .name format") : 0;
	e == 3 ? ft_printf("Bad .comment format") : 0;
	e == 4 ? ft_printf("Missing end quote for .name") : 0;
	e == 5 ? ft_printf("Missing end quote for .comment") : 0;
	e == 6 ? ft_printf("Name can't have more than 128 characters") : 0;
	e == 7 ? ft_printf("Comment can't have more than 2048 characters") : 0;
	e == 8 ? ft_printf("Bad number of argument") : 0;
	e == 9 ? ft_printf("An argument is invalid") : 0;
	e == 10 ? ft_printf("Syntax error") : 0;
	e == 11 ? ft_printf("Double ':' or '%%' in argument") : 0;
	e == 12 ? ft_printf("Label not found in argument") : 0;
	e == 13 ? ft_printf("Error to create the cor file") : 0;
	e == 14 ? ft_printf("Bad character after name declaration") : 0;
	e == 15 ? ft_printf("Bad character after comment declaration") : 0;
	if (!l)
		ft_printf(" at line %d | code error (%d)\n", env ? env->nb_l : -1, e);
	else
		ft_printf(" at line %d | code error (%d)\n", l, e);
	exit(e);
}

void			malloc_error(int e)
{
	ft_printf("Malloc error\n");
	exit(e + 100);
}
