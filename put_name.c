/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 14:20:36 by plefebvr          #+#    #+#             */
/*   Updated: 2017/04/18 19:45:19 by plefebvr         ###   ########.fr       */
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

static void		get_name(char *name, t_env *env, char *line)
{
	char	*tmp;
	int		i;
	int		j;

	ft_printf("get_name function\n");
	i = 0;
	tmp = ft_strsub(name, ft_strlen(NAME_CMD_STRING), \
			ft_strlen(name) - ft_strlen(NAME_CMD_STRING));
	ft_printf("get_name tmp = |%s|\n", tmp);
	while (tmp[i] && (tmp[i] == ' ' || tmp[i] == '\t'))
		i++;
	if (tmp[i] == '"')
	{
		i++;
	}
	else
		asm_error(2);
	j = i;
	ft_printf("after first quote | i = %d\n", i);
	while (tmp[j] && tmp[j] != '"')
		j++;
	env->name = ft_strsub(tmp, i, j - i);
	ft_printf("get_name env->name = %s | i = %d | j = %d\n", env->name, i, j);
	if (!tmp[j])
	{
		while (get_next_line(env->fd, &line) > 0)
		{
	  		if (contain_quote(line))
			{
				last_join(line, env);
				break ;
			}
			else
			{
				env->name = ft_strjoin(env->name, "\n");
				env->name = ft_strjoin(env->name, line);
			}
		}
	}
}

void			put_name(char *l, t_env *env)
{
	int		i;
	char	*trim;
	i = 0;

	ft_printf("Put name\n");
	while (l[i] && (l[i] == ' ' || l[i] == '\t'))
		i++;
	trim = ft_strsub(l, i, ft_strlen(l) - i);
	ft_printf("trim = %s\n", trim);
	if (!(ft_strncmp(trim, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING) \
				&& ((env->ck->status_n++) || env->ck->status_n == 1))))
			get_name(trim, env, NULL);
}
