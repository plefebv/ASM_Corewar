/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 17:40:36 by plefebvr          #+#    #+#             */
/*   Updated: 2017/05/13 08:54:09 by plefebvr         ###   ########.fr       */
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

typedef struct		s_arg
{
	char			*name;
	int				size;
	int				is_label;
	char			*label;
	int				label_pos;
	int				line;
	struct s_arg	*next;
}					t_arg;

typedef struct		s_inst
{
	struct s_label	*label;
	char			*instruction;
	struct s_arg	*arg;
	int				size;
	int				pos;
	int				ocp;
	int				label_size;
	struct s_inst	*next;
}					t_inst;

typedef struct		s_env
{
	char			*name;
	char			*name_file;
	char			*comment;
	t_header		*header;
	int				nb_l;
	int				fd;
	int				have_label;
	t_label			*label;
	t_inst			*inst;
}					t_env;

/*
** Tmp function
*/

void				print_everything(t_env *env);

/*
** Error.c
*/

void				asm_error(int e, t_env *env, int l);
void				malloc_error(int e);

/*
** Parse.c
*/

t_env				*parse_s_file(char *file);

/*
** Put_name.c && put_comment.c
*/

void				put_name(char *l, t_env *env);
void				put_comment(char *l, t_env *env);

/*
** Put_inst.c
*/

void				put_inst(char *l, t_env *env);

/*
** Put_label.c
*/

void				put_label(char *l, t_env *env);

/*
** Utils.c
*/

unsigned int		ft_endian_2_bytes(unsigned int n);
unsigned int		ft_endian_4_bytes(unsigned int n);
void				cut_comment(char **line);
int					get_ocp(char *inst, t_arg *arg);
int					contain_quote(char *s);

/*
** Generate_file.c
*/
void				generate_file(t_env *env);

/*
** Header.c
*/

void				generate_header(t_env *env);

/*
** Check_label.c
*/

void				check_if_label_exist(t_env *env);

/*
** get_arg.c & syntax_arg.c
*/

void				get_arg(char *l, t_inst *inst, t_env *env);
void				arg_syntax_is_valid(char *arg, t_env *env);

/*
** type_of_line.c
*/

int					get_type_line(char *l);
int					get_opcode(char *line);
t_op				*get_optab(char *name);

#endif
