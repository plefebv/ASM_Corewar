/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 23:36:19 by plefebvr          #+#    #+#             */
/*   Updated: 2017/05/14 19:15:37 by plefebvr         ###   ########.fr       */
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

static void			write_header(int fd, t_env *env)
{
	env->header->magic = ft_endian_4_bytes(env->header->magic);
	env->header->prog_size = ft_endian_4_bytes(env->header->prog_size);
	write(fd, env->header, sizeof(t_header));
}

static void			write_cor(t_env *env)
{
	int				fd;
	t_inst			*inst;

	inst = env->inst;
	fd = open(env->name_file, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	fd == -1 ? asm_error(13, NULL, 0) : 0;
	write_header(fd, env);
	write_instruction(fd, env);
}

void				generate_file(t_env *env)
{
	generate_header(env);
	check_last_inst(env);
	//print_everything(env);
	check_if_label_exist(env);
	env->name_file = ft_strjoin_f1(env->name_file, ".cor");
	write_cor(env);
}
