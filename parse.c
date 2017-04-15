/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 18:43:52 by plefebvr          #+#    #+#             */
/*   Updated: 2017/04/15 19:48:04 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"


void			parse_s_file(char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		//Checker ce que contient la ligne
		//Si la ligne n'est pas vide
	}

}
