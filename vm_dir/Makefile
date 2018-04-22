# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brocher <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/16 11:09:18 by brocher           #+#    #+#              #
#    Updated: 2018/04/10 21:11:36 by tmanuel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	../corewar

CC		=	gcc

INC_DIR	=	./includes

CFLAGS	=	-Wall -Wextra -Werror

IFLAGS	=	-I$(INC_DIR) -I ../libft

SRC		=	main_vm.c arena.c champs_id.c cycle_check.c read_analyze.c \
			errors.c process_list.c op_ini.c corewar.c process_functions \
			visu_init.c visu_input.c visu_handle.c visu_draw_windows.c debug.c \
			visu_addendum_a.c inst2.c inst3.c inst4.c exe_cycle.c inst1.c \
			struct_options.c load_argv_options.c check_prc.c op_ini_one.c \
			visu_draw_info.c print.c fill_type.c fill_param.c put_champions.c \
			load_argv_options_extras.c visu_print_heart.c

OBJ		=	$(addprefix $(ODIR)/, $(addsuffix .o, $(basename $(SRC))))

LIBFT_L	=	../libft/libftprintf.a

CURSES	=	-lcurses

ODIR	=	./obj

SDIR	=	./srcs

INCLUDES =  errors.h vm_struct.h op.h vm_proto.h

DEP		=	$(addprefix $(INC_DIR)/, $(INCLUDES)) $(LIBFT_L)

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
	@$(ECHO)
	@tput setaf 10
	@echo -n $@
	@printf "                                  "
	@$(CC) $(OBJ) $(LIBFT_L) $(CURSES) $(IFLAGS) -o $(NAME)
	@printf "\rCorewar done                                                 \n"

clean:
	@tput setaf 9
	@printf "cor fclean\n"
	@/bin/rm -rf $(ODIR)

fclean:
	@tput setaf 9
	@printf "cor fclean\n"
	@/bin/rm -rf $(ODIR)
	@/bin/rm -f $(NAME)

re: fclean all

$(ODIR)/%.o: $(SDIR)/%.c
	@mkdir -p $(ODIR)
	@$(ECHO)
	@tput setaf 10
	@echo -n $@
	@printf "                                  "
	@$(CC) -o $@ -c $(CFLAGS) $(IFLAGS) $<

.PHONY: fclean clean all
