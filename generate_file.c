/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 23:36:19 by plefebvr          #+#    #+#             */
/*   Updated: 2017/05/12 02:50:02 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

static void			check_last_inst(t_env *env)
{
	t_inst		*inst;

	inst = env->inst;
	while (inst->next)
		inst = inst->next;
	if (!inst->instruction)
		inst->pos = env->header->prog_size;
}

void				generate_file(t_env *env)
{
	generate_header(env);
	check_last_inst(env);
	print_everything(env);
	check_if_label_exist(env);
}
