/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:04:52 by plefebvr          #+#    #+#             */
/*   Updated: 2017/05/12 03:51:26 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

/*
** reverse 4 bytes 11000110 00011111 00111111 11111100
*/
unsigned int	ft_endian_4_bytes(unsigned int n)
{
		return ((n >> 24) | ((n & 0xff0000) >> 8) | ((n & 0xff00) << 8) |
						((n & 0xff) << 24));
}

/*
** first convert n to 2 bytes length
** reverse 2 bytes 11000011 00110011
*/

unsigned int	ft_endian_2_bytes(unsigned int n)
{
	n &= 0xffff;
	return ((n >> 8) | ((n & 0xff) << 8));
}

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
