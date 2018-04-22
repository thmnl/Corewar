# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmanuel <tmanuel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 17:13:20 by tmanuel           #+#    #+#              #
#    Updated: 2018/04/19 19:00:28 by tmanuel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../asm

SRC =	srcs/main.c \
		srcs/ft_exit.c \
		srcs/ft_find_line.c \
		srcs/ft_check_error.c \
		srcs/ft_check_error2.c \
		srcs/ft_check_error3.c \
		srcs/ft_check_error4.c \
		srcs/ft_check_error5.c \
		srcs/ft_count_size.c \
		srcs/ft_trad.c \
		srcs/ft_recup_label.c\
		srcs/ft_recup_label2.c\
		srcs/ft_get_label_address.c\
		srcs/ft_instruc.c \
		srcs/ft_instruc2.c \
		srcs/ft_instruc3.c \
		srcs/ft_instruc4.c \
		srcs/ft_instruc5.c \
		srcs/ft_instruc6.c \
		srcs/ft_exit2.c \
		srcs/ft_ope1.c \
		srcs/ft_ope2.c \
		srcs/ft_ope3.c \
		srcs/ft_ope4.c \
		srcs/ft_ope5.c \
		srcs/ft_opevalues.c \
		srcs/ft_count_sep.c \
		srcs/cmd_spe.c \

OBJ = $(patsubst srcs/%.c, %.o, $(SRC))

FLAGS = -Wall -Wextra -Werror

INC = -I includes

LIB = ../libft/libftprintf.a

ifndef ECHO
	T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
		-nrRf $(firstword $(MAKEFILE_LIST)) \
		ECHO="COUNTTHIS" | grep -c "COUNTTHIS")
	N := x
	C = $(words $N)$(eval N := x $N)
	ECHO = printf "\r[`expr $C '*' 100 / $T`%%]"
endif

all: $(NAME)

$(NAME): $(OBJ)
	@tput setaf 10
	@$(ECHO)
	@echo -n $@
	@gcc -g $(FLAGS) $(INC) -o $(NAME) $(OBJ) $(LIB)
	@printf "\rasm done                                  \n"

%.o: srcs/%.c
	@gcc -c $(FLAGS) $(INC) $<
	@tput setaf 10
	@$(ECHO)
	@echo -n $@
	@printf "                                  "

clean:
	@/bin/rm -f $(OBJ)
	@tput setaf 9
	@echo "asm clean"

fclean:
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(OBJ)
	@tput setaf 9
	@echo "asm fclean"

re:
	@make fclean && make

.PHONY: all clean fclean re
