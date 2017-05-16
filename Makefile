# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/15 17:35:10 by plefebvr          #+#    #+#              #
#    Updated: 2017/05/16 23:32:41 by plefebvr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= asm

RM		= /bin/rm -rf

CFLAGS	= -Wall -Wextra
 
FILES	= 	main.c \
			error.c \
			parse.c \
			utils.c \
			type_of_line.c \
			put_name.c \
			put_comment.c \
			put_label.c \
			put_inst.c \
			get_arg.c \
			arg_syntax.c \
			check_arg_type.c \
			generate_file.c \
			check_label.c \
			header.c \
			write_instruction.c \
			write_process.c \
			free.c \

LIB	= -L libft -lft

all:	$(NAME)

CYN = tput bold ; tput setaf 6
RESET = tput sgr 0

$(NAME):
	@make -C libft
	gcc $(CFLAGS) $(FILES) $(LIB) -o $(NAME)
	@$(CYN)
	@echo " === ASM  Compilation Done ===\n"
	@$(RESET)

clean:
	@make -C libft clean
	@$(RM) .obj

fclean: clean
	@make -C libft fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
