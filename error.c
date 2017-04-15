/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 17:51:42 by plefebvr          #+#    #+#             */
/*   Updated: 2017/04/15 18:09:57 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

void			asm_error(int e)
{
		!e ? ft_printf("Please, put at least one s file in argument") : 0;
		ft_printf(" | ERROR CODE (%d)\n", e);
		exit(e);
}
