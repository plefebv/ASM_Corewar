/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 13:23:00 by plefebvr          #+#    #+#             */
/*   Updated: 2017/05/13 14:59:58 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

void		write_instruction(int fd, t_env *env)
{
	t_inst		*inst;

	inst = env->inst;
	while (inst)
	{
		
		inst = inst->next;
	}
