/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 17:51:42 by plefebvr          #+#    #+#             */
/*   Updated: 2017/04/18 19:45:19 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

void			asm_error(int e)
{
		!e ? ft_printf("Put at least one s file in argument") : 0;
		e == 1 ? ft_printf("The file must be a .s") : 0;
		e == 2 ? ft_printf("Bad .name format") : 0;
		ft_printf(" | ERROR CODE (%d)\n", e);
		// FREE CE QU'IL Y A FREE MERCI BIEN MONSIEUR
		exit(e);
}
