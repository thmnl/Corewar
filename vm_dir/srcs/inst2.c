/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 12:55:27 by brocher           #+#    #+#             */
/*   Updated: 2018/04/09 12:55:28 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_struct.h"
#include "vm_proto.h"
#include "errors.h"

void	inst_add(t_prc *prc, t_inst *inst, t_op *op_tab)
{
	int		tot;

	tot = 0;
	tot += get_from_reg(prc, inst->prm[0]);
	tot += get_from_reg(prc, inst->prm[1]);
	put_in_reg(prc, inst->prm[2], tot);
	modify_carry(prc, tot);
	move_pc(prc, op_tab);
}

void	inst_sub(t_prc *prc, t_inst *inst, t_op *op_tab)
{
	int		tot;

	tot = 0;
	tot += get_from_reg(prc, inst->prm[0]);
	tot -= get_from_reg(prc, inst->prm[1]);
	put_in_reg(prc, inst->prm[2], tot);
	modify_carry(prc, tot);
	move_pc(prc, op_tab);
}

void	inst_and(t_prc *prc, t_inst *inst, t_op *op_tab)
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
	tot = p0 & p1;
	put_in_reg(prc, inst->prm[2], tot);
	modify_carry(prc, tot);
	move_pc(prc, op_tab);
}

void	inst_or(t_prc *prc, t_inst *inst, t_op *op_tab)
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
	tot = p0 | p1;
	put_in_reg(prc, inst->prm[2], tot);
	modify_carry(prc, tot);
	move_pc(prc, op_tab);
}

void	inst_xor(t_prc *prc, t_inst *inst, t_op *op_tab)
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
	tot = p0 ^ p1;
	put_in_reg(prc, inst->prm[2], tot);
	modify_carry(prc, tot);
	move_pc(prc, op_tab);
}
