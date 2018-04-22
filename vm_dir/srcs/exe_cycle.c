/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <brocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 12:54:37 by brocher           #+#    #+#             */
/*   Updated: 2018/04/20 14:38:01 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_struct.h"
#include "vm_proto.h"
#include "errors.h"
#include "visu.h"

void		exe_inst_next(t_vm *vm, t_prc *prc, t_op *op_tab)
{
	if (prc->op == 10)
		inst_ldi(vm, prc, &(prc->inst), op_tab);
	else if (prc->op == 11)
		inst_sti(vm, prc, &(prc->inst), op_tab);
	else if (prc->op == 12)
		inst_fork(vm, prc, &(prc->inst), op_tab);
	else if (prc->op == 13)
		inst_lld(prc, &(prc->inst), op_tab);
	else if (prc->op == 14)
		inst_lldi(vm, prc, &(prc->inst), op_tab);
	else if (prc->op == 15)
		inst_lfork(vm, prc, &(prc->inst), op_tab);
	else if (prc->op == 16)
		inst_aff(vm, prc, &(prc->inst), op_tab);
}

void		exe_inst(t_vm *vm, t_champ *champ, t_prc *prc, t_op *op_tab)
{
	if (prc->op == 1)
		inst_live(vm, champ, prc, op_tab);
	else if (prc->op == 2)
		inst_ld(prc, &(prc->inst), op_tab);
	else if (prc->op == 3)
		inst_st(vm, prc, &(prc->inst), op_tab);
	else if (prc->op == 4)
		inst_add(prc, &(prc->inst), op_tab);
	else if (prc->op == 5)
		inst_sub(prc, &(prc->inst), op_tab);
	else if (prc->op == 6)
		inst_and(prc, &(prc->inst), op_tab);
	else if (prc->op == 7)
		inst_or(prc, &(prc->inst), op_tab);
	else if (prc->op == 8)
		inst_xor(prc, &(prc->inst), op_tab);
	else if (prc->op == 9)
		inst_zjmp(prc, &(prc->inst), op_tab);
	else
		exe_inst_next(vm, prc, op_tab);
}

int			launch_inst(t_vm *vm, t_champ *champ, t_prc *prc, t_op *op_tab)
{
	if (check_inst(&(vm->arn[prc->pc % MEM_SIZE]), prc->op, op_tab) == 1)
	{
		fill_type(vm, prc, op_tab);
		fill_param(vm, prc, op_tab);
	}
	else
	{
		if (fill_type(vm, prc, op_tab) == 1)
			move_pc(prc, op_tab);
		else
			(prc->pc)++;
		rini_prc(prc);
		return (0);
	}
	if (check_reg_nb(&(prc->inst)))
		exe_inst(vm, champ, prc, op_tab);
	else
		move_pc(prc, op_tab);
	if (prc->op == 12 || prc->op == 15)
	{
		rini_prc(prc);
		return (1);
	}
	rini_prc(prc);
	return (0);
}

int			exe_process(t_vm *vm, t_champ *champ, t_prc *prc, t_op *op_tab)
{
	if (prc->live == -1)
		return (1);
	if (prc->op == 0)
	{
		if (vm->arn[prc->pc % MEM_SIZE] < 1 || vm->arn[prc->pc % MEM_SIZE] > 16)
			prc->pc = (prc->pc + 1) % MEM_SIZE;
		else
		{
			prc->op = vm->arn[prc->pc % MEM_SIZE];
			(prc->wait)++;
		}
	}
	else if (prc->wait >= op_tab[(int)prc->op - 1].cycle - 1)
		return (launch_inst(vm, champ, prc, op_tab));
	else
		(prc->wait)++;
	return (0);
}

void		exe_cycle(t_vm *vm, t_champ *champ, t_op *op_tab)
{
	int		ord;
	t_prc	*prc;

	ord = 0;
	while (ord < vm->nb_champs_org)
	{
		prc = champ[ord].prc;
		while (prc != NULL)
		{
			exe_process(vm, champ, prc, op_tab);
			prc = prc->next;
		}
		ord++;
	}
}
