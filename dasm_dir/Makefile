# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmanuel <tmanuel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 17:13:20 by tmanuel           #+#    #+#              #
#    Updated: 2018/04/17 20:50:43 by tmanuel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../dasm

SRC =	srcs/main.c \
		srcs/ft_exit.c \
		srcs/ft_decrypt.c \
		srcs/ft_decrypt2.c \
		srcs/ft_instruc.c \
		srcs/ft_instruc2.c \
		srcs/ft_instruc3.c \
		srcs/ft_instruc4.c \

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
	@printf "\rdasm done                                  \n"

%.o: srcs/%.c
	@gcc -c $(FLAGS) $(INC) $<
	@tput setaf 10
	@$(ECHO)
	@echo -n $@
	@printf "                                  "

clean:
	@/bin/rm -f $(OBJ)
	@tput setaf 9
	@echo "dasm clean"

fclean:
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(OBJ)
	@tput setaf 9
	@echo "dasm fclean"

re:
	@make fclean && make

.PHONY: all clean fclean re
