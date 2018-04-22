/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 12:55:18 by brocher           #+#    #+#             */
/*   Updated: 2018/04/09 12:55:20 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_struct.h"
#include "vm_proto.h"
#include "errors.h"
#include "visu.h"

void	modify_carry(t_prc *prc, int res)
{
	if (res == 0)
		prc->carry = 1;
	else
		prc->carry = 0;
}

void	inst_live(t_vm *vm, t_champ *champ, t_prc *prc, t_op *op_tab)
{
	int		i;

	i = 0;
	while (i < vm->nb_champs_org)
	{
		if (vm->id[i] == prc->inst.prm[0])
		{
			(vm->live[i])++;
			vm->winner_id = prc->inst.prm[0];
			if (!vm->option->mute)
				ft_printf("un processus dit que le joueur %d (%s) est en vie\n"\
						, champ[i].id, champ[i].name);
		}
		i++;
	}
	prc->live = 1;
	move_pc(prc, op_tab);
}

void	inst_st(t_vm *vm, t_prc *prc, t_inst *inst, t_op *op_tab)
{
	int		i;

	if (inst->type[1] == 1)
		put_in_reg(prc, inst->prm[1], get_from_reg(prc, inst->prm[0]));
	else
	{
		i = 0;
		while (i < REG_SIZE)
		{
			put_in_arena(vm, prc->pc + (inst->prm[1] % IDX_MOD) + i, \
					prc->reg[(inst->prm[0] - 1) * REG_SIZE + i]);
			put_in_color(vm, prc->pc + (inst->prm[1] % IDX_MOD) + i, \
					vm->color[prc->pc % MEM_SIZE]);
			put_in_highlight(vm, prc->pc + (inst->prm[1] % IDX_MOD) + \
					i, HIGHLIGHT);
			i++;
		}
	}
	move_pc(prc, op_tab);
}

void	inst_zjmp(t_prc *prc, t_inst *inst, t_op *op_tab)
{
	if (prc->carry == 1)
		prc->pc += inst->prm[0] % IDX_MOD;
	else
		move_pc(prc, op_tab);
	while (prc->pc < 0)
		prc->pc += MEM_SIZE;
}

void	inst_sti(t_vm *vm, t_prc *prc, t_inst *inst, t_op *op_tab)
{
	int		tot;
	int		i;

	if (inst->type[1] == 1)
		inst->prm[1] = get_from_reg(prc, inst->prm[1]);
	if (inst->type[2] == 1)
		inst->prm[2] = get_from_reg(prc, inst->prm[2]);
	tot = inst->prm[1] + inst->prm[2];
	i = 0;
	while (i < REG_SIZE)
	{
		put_in_arena(vm, prc->pc + (tot % IDX_MOD) + i, \
				prc->reg[(inst->prm[0] - 1) * REG_SIZE + i]);
		put_in_color(vm, prc->pc + (tot % IDX_MOD) + i, \
				vm->color[prc->pc % MEM_SIZE]);
		put_in_highlight(vm, prc->pc + (tot % IDX_MOD) + i, 10);
		i++;
	}
	move_pc(prc, op_tab);
}
