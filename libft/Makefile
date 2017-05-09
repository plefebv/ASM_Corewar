# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/21 10:45:45 by plefebvr          #+#    #+#              #
#    Updated: 2017/05/09 14:01:53 by plefebvr         ###   ########.fr        #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_isprint.c \
		ft_memalloc.c \
		ft_putchar.c \
		ft_square.c \
		ft_strequ.c \
		ft_strncat.c \
		ft_strstr.c \
		ft_itoa.c \
		ft_memccpy.c \
		ft_putchar_fd.c \
		ft_strcat.c \
		ft_striter.c \
		ft_strncmp.c \
		ft_strsub.c \
		ft_atoi.c \
		ft_atoi_base.c \
		ft_lstadd.c \
		ft_memchr.c \
		ft_putendl.c \
		ft_strchr.c \
		ft_striteri.c \
		ft_strncpy.c \
		ft_strtrim.c \
		ft_bzero.c \
		ft_lstdel.c \
		ft_memcmp.c \
		ft_putendl_fd.c \
		ft_strclr.c \
		ft_strjoin.c \
		ft_strjoin_f1.c \
		ft_strjoin_f2.c \
		ft_strjoin_f.c \
		ft_strnequ.c \
		ft_strtrim_f.c \
		ft_tolower.c \
		ft_isalnum.c \
		ft_lstdelone.c \
		ft_memcpy.c \
		ft_putnbr.c \
		ft_strcmp.c \
		ft_strlcat.c \
		ft_strnew.c \
		ft_toupper.c \
		ft_isalpha.c \
		ft_lstiter.c \
		ft_memdel.c \
		ft_putnbr_fd.c \
		ft_strcpy.c \
		ft_strlen.c \
		ft_strnstr.c \
		ft_wordcount.c \
		ft_isascii.c \
		ft_lstmap.c \
		ft_memmove.c \
		ft_putstr.c \
		ft_strdel.c \
		ft_strmap.c \
		ft_strrchr.c \
		ft_isdigit.c \
		ft_lstnew.c \
		ft_memset.c \
		ft_putstr_fd.c \
		ft_strdup.c \
		ft_power.c \
		ft_strmapi.c \
		ft_strsplit.c \
		ft_nbrendl.c \
		ft_strndup.c \
		ft_checkchar.c \
		ft_strtolower.c \
		ft_strdup_f.c \
		ft_strsub_f.c \
		ft_strrealloc.c \
		get_next_line.c \
		ft_printf.c \
		pf_lst_utils.c \
		pf_first_utils.c\
		pf_flag.c \
		pf_parse.c \
		pf_init.c \
		pf_work.c \
		pf_dioux.c \
		pf_itoa_ll.c \
		pf_add_sign.c \
		pf_parse_letter.c \
		pf_precision_dioux.c \
		pf_minfield.c \
		pf_di.c \
		pf_u.c \
		pf_sc.c \
		pf_put_c.c \
		pf_put_s.c \
		pf_nbrlen_str.c \
		pf_spe.c \
		pf_null.c \
		pf_hex.c \
		pf_octal.c \
		pf_precision_s.c

OBJ =	$(SRC:.c=.o)	
HEADER = includes/libft.h
FLAG = -Wall -Wextra -Werror

CYN = tput bold ; tput setaf 6
BLU = tput bold ; tput setaf 4
GRN = tput bold ; tput setaf 2
YLW = tput bold ; tput setaf 3
RESET = tput sgr 0

all: $(NAME)

$(NAME) :
	@$(CYN)
	@echo " === Libft Compilation Beggining ===\n"
	@$(BLU)
	@echo "	Create Libft objects"
	@gcc $(FLAG) -c $(SRC) -I $(HEADER)
	@echo "	Create libft.a\n"
	@/usr/bin/ar rc $(NAME) $(OBJ)
	@/usr/bin/ranlib $(NAME)
	@$(CYN)
	@echo " === Libft Compilation Done  ==="
	@$(RESET)

clean:
	@/bin/rm -f $(OBJ)
	@$(BLU)
	@echo "	Clean Libft objects Done !"
	@$(RESET)

fclean: clean
	@/bin/rm -f $(NAME)
	@$(BLU)
	@echo "	Clean Libft libft.a Done !"
	@$(RESET)


re: fclean all
