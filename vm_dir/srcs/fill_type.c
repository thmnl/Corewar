/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 12:55:07 by brocher           #+#    #+#             */
/*   Updated: 2018/04/09 12:55:09 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_struct.h"
#include "vm_proto.h"
#include "errors.h"

char		fill_type_encoding(t_vm *vm, int pc, t_inst *inst)
{
	char			cod;
	unsigned char	tmp;
	int				i;

	i = 0;
	cod = vm->arn[pc % MEM_SIZE];
	while (i < 3)
	{
		tmp = cod & 0xC0;
		if (tmp == 0x80)
			inst->type[i] = 4;
		else if (tmp == 0xC0)
			inst->type[i] = 2;
		else if (tmp == 0x40)
			inst->type[i] = 1;
		else if (tmp == 0x00)
			inst->type[i] = 0;
		else
			return (0);
		cod = cod << 2;
		i++;
	}
	return (1);
}

void		fill_type_op(t_prc *prc)
{
	prc->inst.type[1] = 0;
	prc->inst.type[2] = 0;
	if (prc->op == 16)
		prc->inst.type[0] = 1;
	else
		prc->inst.type[0] = 4;
}

char		fill_type(t_vm *vm, t_prc *prc, t_op *op_tab)
{
	int		mem;

	mem = prc->pc;
	prc->inst.type[0] = 0;
	prc->inst.type[1] = 0;
	prc->inst.type[2] = 0;
	if (op_tab[prc->op - 1].encoding == 1)
	{
		mem++;
		if (fill_type_encoding(vm, mem, &(prc->inst)) == 0)
			return (0);
	}
	else
		fill_type_op(prc);
	prc->inst.prm[0] = 0;
	prc->inst.prm[1] = 0;
	prc->inst.prm[2] = 0;
	return (1);
}
