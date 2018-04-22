/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 12:55:36 by brocher           #+#    #+#             */
/*   Updated: 2018/04/09 12:55:38 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_struct.h"
#include "vm_proto.h"
#include "errors.h"
#include "visu.h"

void	inst_ld(t_prc *prc, t_inst *inst, t_op *op_tab)
{
	put_in_reg(prc, inst->prm[1], inst->prm[0]);
	modify_carry(prc, inst->prm[0]);
	move_pc(prc, op_tab);
}

void	inst_lld(t_prc *prc, t_inst *inst, t_op *op_tab)
{
	put_in_reg(prc, inst->prm[1], inst->prm[0]);
	modify_carry(prc, inst->prm[0]);
	move_pc(prc, op_tab);
}

void	inst_ldi(t_vm *vm, t_prc *prc, t_inst *inst, t_op *op_tab)
{
	int		tot;
	int		p0;
	int		p1;

	if (inst->type[0] == 1)
		p0 = get_from_reg(prc, inst->prm[0]);
	else
		p0 = inst->prm[0];
	if (inst->type[1] == 1)
		p1 = get_from_reg(prc, inst->prm[1]);
	else
		p1 = inst->prm[1];
	tot = p0 + p1;
	get_from_arena(vm, prc, inst->prm[2], tot % IDX_MOD);
	move_pc(prc, op_tab);
}

void	inst_lldi(t_vm *vm, t_prc *prc, t_inst *inst, t_op *op_tab)
{
	int		tot;
	int		p0;
	int		p1;

	if (inst->type[0] == 1)
		p0 = get_from_reg(prc, inst->prm[0]);
	else
		p0 = inst->prm[0];
	if (inst->type[1] == 1)
		p1 = get_from_reg(prc, inst->prm[1]);
	else
		p1 = inst->prm[1];
	tot = p0 + p1;
	get_from_arena(vm, prc, inst->prm[2], tot);
	modify_carry(prc, get_from_reg(prc, inst->prm[2]));
	move_pc(prc, op_tab);
}
