/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 14:20:36 by plefebvr          #+#    #+#             */
/*   Updated: 2017/05/04 23:09:59 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

static int		contain_quote(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '"')
			return (1);
		i++;
	}
	return (0);
}

static void		last_join(char *s, t_env *env)
{
	int		i;
	char	*tojoin;

	i = 0;
	while (s[i] && s[i] != '"')
		i++;
	tojoin = ft_strsub(s, 0, i);
	env->name = ft_strjoin(env->name, "\n");
	env->name = ft_strjoin(env->name, tojoin);
	ft_memdel((void **)&tojoin);
}

static void		get_name(char *name, t_env *env, char *line, int c)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	tmp = ft_strsub(name, ft_strlen(NAME_CMD_STRING), \
			ft_strlen(name) - ft_strlen(NAME_CMD_STRING));
	while (tmp[i] && (tmp[i] == ' ' || tmp[i] == '\t'))
		i++;
	if (tmp[i] == '"')
	{
		i++;
	}
	else
		asm_error(2, env->nb_l);
	j = i;
	while (tmp[j] && tmp[j] != '"')
		j++;
	env->name = ft_strsub(tmp, i, j - i);
	if (!tmp[j])
	{
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
				env->name = ft_strjoin(env->name, "\n");
				env->name = ft_strjoin(env->name, line);
			}
		}
		if (!c)
			asm_error(4, env->nb_l);
	}
}

void			put_name(char *l, t_env *env)
{
	int		i;
	char	*trim;
	i = 0;

	while (l[i] && (l[i] == ' ' || l[i] == '\t'))
		i++;
	trim = ft_strsub(l, i, ft_strlen(l) - i);
	if (!(ft_strncmp(trim, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING))))
			get_name(trim, env, NULL, 0);
	if (ft_strlen(env->name) > PROG_NAME_LENGTH)
		asm_error(6, env->nb_l);
}