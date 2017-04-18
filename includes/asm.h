/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 17:40:36 by plefebvr          #+#    #+#             */
/*   Updated: 2017/04/18 19:45:19 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/includes/libft.h"
# include "op.h"
# include <fcntl.h>


typedef struct		s_ck
{
	int				new_line_n;
	int				new_line_c;
	int				status_n;
	int				status_c;
	int				nc_done;
}					t_ck;

typedef struct		s_label
{
	char			*name;
	int				original;
	struct s_label	*next;
}					t_label;

typedef struct		s_env
{
	char			*name;
	char			*name_file;
	char			*comment;
	int				nb_l;
	int				fd;
	t_label			*label;
	t_ck			*ck;
}					t_env;

void				asm_error(int e);
void				parse_s_file(char *file);
void				put_name(char *l, t_env *env);
void				put_comment(char *l, t_env *env);

int					get_type_line(char *l);

#endif
