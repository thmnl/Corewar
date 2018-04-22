/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 12:54:58 by brocher           #+#    #+#             */
/*   Updated: 2018/04/09 12:54:59 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_struct.h"
#include "vm_proto.h"
#include "errors.h"

int			change_carry(int prm, char size)
{
	int		carry;

	prm = prm << ((4 - size) * 8);
	if ((prm & 0x80000000) == 0x80000000)
	{
		prm = prm & 0x7FFFFFFF;
		prm = prm >> ((4 - size) * 8);
		carry = 0x00000080;
		carry = carry << ((size - 1) * 8);
		prm = prm - carry;
	}
	else
	{
		prm = prm >> ((4 - size) * 8);
	}
	return (prm);
}

int			read_prm(t_vm *vm, int pc, char size)
{
	int		i;
	int		prm;
	int		tmp;
	char	conv;

	i = 0;
	prm = 0;
	while (i < size)
	{
		if (vm->arn[(pc + i) % MEM_SIZE] >= 0)
			tmp = (int)vm->arn[(pc + i) % MEM_SIZE];
		else
		{
			conv = vm->arn[(pc + i) % MEM_SIZE] & 0x7F;
			tmp = (int)conv;
			tmp = tmp | 0x80;
		}
		tmp = tmp << (8 * (size - 1 - i));
		prm = prm | tmp;
		i++;
	}
	prm = change_carry(prm, size);
	return (prm);
}

void		fill_param(t_vm *vm, t_prc *prc, t_op *op_tab)
{
	int		i;
	int		mem;

	mem = prc->pc;
	(mem)++;
	if (op_tab[prc->op - 1].encoding == 1)
		mem++;
	i = 0;
	while (i < 3)
	{
		prc->inst.prm[i] = read_prm(vm, mem, prc->inst.type[i] - \
				(prc->inst.type[i] == 4 && op_tab[prc->op - 1].size == 1) * 2);
		if (prc->inst.type[i] == 2 && (prc->op == 3 || prc->op == 11))
			;
		else if (prc->inst.type[i] == 2 && (prc->op == 13 || prc->op == 14))
			prc->inst.prm[i] = read_prm(vm, prc->pc + prc->inst.prm[i], 4);
		else if (prc->inst.type[i] == 2)
			prc->inst.prm[i] = read_prm(vm, prc->pc + \
					(prc->inst.prm[i] % IDX_MOD), 4);
		mem += prc->inst.type[i] - (prc->inst.type[i] == 4 && \
				op_tab[prc->op - 1].size == 1) * 2;
		i++;
	}
}
