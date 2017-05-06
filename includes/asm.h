/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 17:40:36 by plefebvr          #+#    #+#             */
/*   Updated: 2017/05/06 02:26:00 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/includes/libft.h"
# include "op.h"
# include <fcntl.h>

typedef struct		s_label
{
	char			*name;
	int				original;
	struct s_label	*next;
}					t_label;

typedef struct		s_inst
{
	char			*label;
	char			*instruction;
	char			**arg;
	int				size;
	int				pos;
	int				ocp;
	int				label_size;
	struct s_int	*next;
}					t_inst;

typedef struct		s_env
{
	char			*name;
	char			*name_file;
	char			*comment;
	int				nb_l;
	int				fd;
	int				have_label;
	t_label			*label;
	t_inst			*inst;
}					t_env;

void				asm_error(int e, int l);
void				parse_s_file(char *file);
void				put_name(char *l, t_env *env);
void				put_comment(char *l, t_env *env);
void				put_declaration_label(char *l, t_env *env);
void				put_inst(char *l, t_env *env);

int					get_type_line(char *l);

#endif
