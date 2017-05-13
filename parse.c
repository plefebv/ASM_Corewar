/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 18:43:52 by plefebvr          #+#    #+#             */
/*   Updated: 2017/05/13 08:02:58 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

static void		put_file_name(char *file, t_env *env)
{
	char		*ext;
	char		*tmp_name;

	tmp_name = ft_strsub(file, 0, ft_strlen(file) - 2);
	ext = ft_strsub(file, ft_strlen(file) - 2, ft_strlen(file) - 1);
	if (ft_strcmp(ext, ".s") == 0)
		env->name_file = ft_strdup_f(tmp_name);
	else
	{
		ft_memdel((void **)&ext);
		ft_memdel((void **)&tmp_name);
		asm_error(1, NULL, 0);
	}
	ft_memdel((void **)&ext);
}

static void		init(t_env *env)
{
	env->name = NULL;
	env->name_file = NULL;
	env->comment = NULL;
	env->header = NULL;
	env->inst = NULL;
	env->nb_l = 0;
	env->fd = -1;
}

t_env			*parse_s_file(char *file)
{
	t_env	*env;
	char	*line;
	int		line_type;


	env = (t_env *)ft_memalloc(sizeof(t_env));
	init(env);
	put_file_name(file, env);
	env->fd = open(file, O_RDONLY);
	while (get_next_line(env->fd, &line) > 0)	
	{
		env->nb_l++;
		line_type = get_type_line(line);
		cut_comment(&line);
		line_type == 3 ? put_name(line, env) : 0;
		line_type == 4 ? put_comment(line, env) : 0;
		line_type == 5 ? put_label(line, env) : 0;
		line_type >= -1 && line_type <= 5 ? 0 : put_inst(line, env);
		free(line);
		line_type == -1 ? asm_error(10, env, 0) : 0;
	}
	return (env);
}
