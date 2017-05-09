/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 14:20:36 by plefebvr          #+#    #+#             */
/*   Updated: 2017/05/09 14:44:52 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

static void		last_join(char *s, t_env *env)
{
	int		i;
	char	*tojoin;

	i = 0;
	while (s[i] && s[i] != '"')
		i++;
	tojoin = ft_strsub(s, 0, i);
	env->comment = ft_strjoin_f1(env->comment, "\n");
	env->comment = ft_strjoin_f1(env->comment, tojoin);
	ft_memdel((void **)&tojoin);
}

static void		comment_process(t_env *env)
{
	char	c;
	char	*line;

	line = NULL;
	c = 0;	
	while (get_next_line(env->fd, &line) > 0)
	{
		env->nb_l++;
		if (contain_quote(line))
		{
			c++;
			last_join(line, env);
			break ;
		}
		else
		{
			env->comment = ft_strjoin_f1(env->comment, "\n");
			env->comment = ft_strjoin_f1(env->comment, line);
		}
	}
	if (!c)
		asm_error(5, env->nb_l);
}

static void		get_comment(char *comment, t_env *env)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	tmp = ft_strsub(comment, ft_strlen(COMMENT_CMD_STRING), \
			ft_strlen(comment) - ft_strlen(COMMENT_CMD_STRING));
	while (tmp[i] && (tmp[i] == ' ' || tmp[i] == '\t'))
		i++;
	if (tmp[i] == '"')
		i++;
	else
		asm_error(3, env->nb_l);
	j = i;
	while (tmp[j] && tmp[j] != '"')
		j++;
	env->comment = ft_strsub(tmp, i, j - i);
	if (!tmp[j])
		comment_process(env);
}

void			put_comment(char *l, t_env *env)
{
	int		i;
	char	*trim;
	i = 0;

	while (l[i] && (l[i] == ' ' || l[i] == '\t'))
		i++;
	trim = ft_strsub(l, i, ft_strlen(l) - i);
	if (!(ft_strncmp(trim, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING))))
			get_comment(trim, env);
	if (ft_strlen(env->comment) > COMMENT_LENGTH)
		asm_error(7, env->nb_l);
}
