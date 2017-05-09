/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:04:52 by plefebvr          #+#    #+#             */
/*   Updated: 2017/05/09 16:04:47 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

int			contain_quote(char *s)
{
	int			i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '"')
			return (1);
		i++;
	}
	return (0);
}

void			cut_comment(char **line)
{
	int		i;
	int		todo;

	i = 0;
	todo = 0;
	while (line[0][i])
	{
		if (line[0][i] == '#' || line[0][i] == ';')
		{
			todo++;
			break ;
		}
		i++;
	}
	if (todo && i >= 1)
	{
		line[0] = ft_strsub_f(line[0], 0, i);
		line[0] = ft_strtrim_f(line[0]);
	}
}
