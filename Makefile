# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 17:13:20 by tmanuel           #+#    #+#              #
#    Updated: 2018/04/17 20:51:02 by tmanuel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@make -C libft
	@make -C vm_dir
	@make -C asm_dir
	@make -C dasm_dir

clean:
	@make clean -C libft
	@make clean -C vm_dir
	@make clean -C asm_dir
	@make clean -C dasm_dir

fclean:	
	@make fclean -C libft
	@make fclean -C vm_dir
	@make fclean -C asm_dir
	@make fclean -C dasm_dir

re: fclean all

.PHONY: fclean clean all
