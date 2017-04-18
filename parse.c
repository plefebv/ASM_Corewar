/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 18:43:52 by plefebvr          #+#    #+#             */
/*   Updated: 2017/04/18 19:45:19 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

static void		put_file_name(char *file, t_env *env)
{
	char		*ext;
	char		*tmp_name;

	env = (t_env *)ft_memalloc(sizeof(t_env));
	tmp_name = ft_strsub(file, 0, ft_strlen(file) - 2);
	ext = ft_strsub(file, ft_strlen(file) - 2, ft_strlen(file) - 1);
	if (ft_strcmp(ext, ".s") == 0)
		env->name_file = tmp_name;
	else
	{
		ft_memdel((void **)&ext);
		ft_memdel((void **)&tmp_name);
		asm_error(1);
	}
	ft_memdel((void **)&ext);
}

static void		init(t_env *env)
{
	ft_printf("init 0\n");
	env->name = NULL;
	env->name_file = NULL;
	env->comment = NULL;
	env->nb_l = 0;
	env->fd = -1;
	ft_printf("init 1\n");
	env->ck = (t_ck *)ft_memalloc(sizeof(t_ck));
	env->ck->new_line_n = 0;
	env->ck->new_line_c = 0;
	env->ck->nc_done = 0;
	ft_printf("init 2\n");
}
void			parse_s_file(char *file)
{
	char	*line;
	int		line_type;
	t_env	*env;


	ft_printf("parse 0\n");
	env = (t_env *)ft_memalloc(sizeof(t_env));
	ft_printf("parse 1\n");
	init(env);
	ft_printf("parse 2\n");
	put_file_name(file, env);
	ft_printf("parse 3\n");
	env->fd = open(file, O_RDONLY);
	ft_printf("parse 4\n");
	while (get_next_line(env->fd, &line) > 0)
	{
		ft_printf("GNL = %s  | ", line);
		line_type = get_type_line(line);
		ft_printf("Type = %d\n", line_type);
		if (line_type == 3)
			put_name(line, env);
		ft_printf("env->name = |%s|\n", env->name);
		/*if (env->ck.new_line_c == 1 || line_type == 4)
			put_comment(line, env);*/
		//if (line_type == 5)
		//	put_label(
	}

}
