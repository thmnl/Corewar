/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <brocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 12:55:48 by brocher           #+#    #+#             */
/*   Updated: 2018/04/19 17:54:15 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_struct.h"
#include "vm_proto.h"
#include "errors.h"
#include "visu.h"

void	inst_fork(t_vm *vm, t_prc *prc, t_inst *inst, t_op *op_tab)
{
	t_prc	*new;

	new = (t_prc *)safe_malloc(sizeof(t_prc));
	new->pc = prc->pc + (inst->prm[0] % IDX_MOD);
	while (new->pc < 0)
		new->pc += MEM_SIZE;
	ft_memcpy(new->reg, prc->reg, REG_NUMBER * REG_SIZE);
	new->carry = prc->carry;
	new->next = prc->next;
	rini_inst(prc);
	new->op = 0;
	new->wait = 0;
	new->live = 1;
	prc->next = new;
	move_pc(prc, op_tab);
	(vm->nb_process)++;
}

void	inst_lfork(t_vm *vm, t_prc *prc, t_inst *inst, t_op *op_tab)
{
	t_prc	*new;

	new = (t_prc *)safe_malloc(sizeof(t_prc));
	new->pc = prc->pc + inst->prm[0];
	while (new->pc < 0)
		new->pc += MEM_SIZE;
	ft_memcpy(new->reg, prc->reg, REG_NUMBER * REG_SIZE);
	new->carry = prc->carry;
	new->next = prc->next;
	rini_inst(prc);
	new->op = 0;
	new->wait = 0;
	new->live = 1;
	prc->next = new;
	move_pc(prc, op_tab);
	(vm->nb_process)++;
}

void	inst_aff(t_vm *vm, t_prc *prc, t_inst *inst, t_op *op_tab)
{
	int		tot;

	tot = get_from_reg(prc, inst->prm[0]) % 256;
	if (vm->option->dump == 0)
		ft_printf("%c", (char)tot);
	move_pc(prc, op_tab);
}
