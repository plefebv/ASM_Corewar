/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 17:51:42 by plefebvr          #+#    #+#             */
/*   Updated: 2017/04/28 16:59:26 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

void			test_error(int e)
{
	ft_printf("Test error n*%d\n", e);
	exit(e);
}

void			asm_error(int e, int l)
{
		!e ? ft_printf("Put at least one s file in argument") : 0;
		e == 1 ? ft_printf("The file must be a .s") : 0;
		e == 2 ? ft_printf("Bad .name format") : 0;
		e == 3 ? ft_printf("Bad .comment format") : 0;
		e == 4 ? ft_printf("Missing end quote for .name") : 0;
		e == 5 ? ft_printf("Missing end quote for .comment") : 0;
		e == 6 ? ft_printf("Name can't have more than 128 characters") : 0;
		e == 7 ? ft_printf("Comment can't have more than 2048 characters") : 0;
		ft_printf(" | ERROR CODE (%d) at line %d\n", e, l);
		// FREE CE QU'IL Y A FREE MERCI BIEN MONSIEUR
		exit(e);
}

void			malloc_error(int e)
{
	ft_printf("Malloc error\n");
	exit(e + 100);
}
