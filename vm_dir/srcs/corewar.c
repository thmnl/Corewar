/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <brocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 12:53:51 by brocher           #+#    #+#             */
/*   Updated: 2018/04/20 15:28:28 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_struct.h"
#include "vm_proto.h"
#include "errors.h"
#include "visu.h"

void		decrease_highlight(t_vm *vm)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (vm->highlight[i] > 0)
			(vm->highlight[i])--;
		i++;
	}
}

void		announce_winner(t_vm *vm, t_champ *champ)
{
	int		i;

	i = 0;
	while (i < vm->nb_champs_org)
	{
		if (champ[i].id == vm->winner_id)
			ft_printf("le joueur %d (%s) a gagne\n", \
					vm->winner_id, champ[i].name);
		i++;
	}
	if (vm->option->dump && vm->nb_cycles < vm->option->dump_cycles)
		dump_memory(*vm);
}

void		corewar(t_vm *vm, t_champ *champ, t_op *op_tab, t_visu *visu)
{
	while (check_cycle(vm, champ))
	{
		exe_cycle(vm, champ, op_tab);
		if (vm->option->graphic)
			if (!handle_ncurses(vm, champ, visu))
				break ;
		mvprintw(66, 5, "");
		decrease_highlight(vm);
		(vm->nb_cycles)++;
		(vm->cycle_new)++;
		if (vm->option->debug)
		{
			if (vm->nb_cycles == vm->option->debug_nbr)
			{
				print_arena(*vm, champ);
				usleep(500000);
			}
		}
	}
}

void		begin_war(t_vm *vm, t_champ *champ)
{
	t_op	*op_tab;
	t_visu	*visu;
	int		i;

	op_tab = ini_op_tab();
	visu = NULL;
	if (vm->option->graphic)
		visu = visu_init(champ, vm->nb_champs_org);
	corewar(vm, champ, op_tab, visu);
	endwin();
	announce_winner(vm, champ);
	i = 0;
	while (i < 16)
	{
		free(op_tab[i].name);
		free(op_tab[i].comment);
		i++;
	}
	free(op_tab);
	if (vm->option->graphic)
	{
		free(visu->last_live);
		free(visu->last_cycle);
		free(visu);
	}
}
