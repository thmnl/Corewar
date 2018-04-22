/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_prc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 12:53:38 by brocher           #+#    #+#             */
/*   Updated: 2018/04/09 12:53:40 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_struct.h"
#include "vm_proto.h"
#include "errors.h"
#include "visu.h"

char		check_inst(char *mem, int op, t_op *op_tab)
{
	unsigned char	cod;

	if (op_tab[op - 1].encoding == 0)
		return (1);
	cod = (unsigned char)mem[1 % MEM_SIZE];
	if ((op == 2 && (cod == 144 || cod == 208)) || \
			(op == 3 && (cod == 112 || cod == 80)))
		return (1);
	if ((op == 4 || op == 5) && cod == 84)
		return (1);
	if ((op == 6 || op == 7 || op == 8) && (cod == 84 || cod == 116 || cod == \
				100 || cod == 164 || cod == 148 || cod == 180 || cod == 228 || \
				cod == 212 || cod == 244))
		return (1);
	if ((op == 10 || op == 14) && (cod == 84 || cod == 100 || cod == 164 || \
				cod == 148 || cod == 212 || cod == 228))
		return (1);
	if (op == 11 && (cod == 84 || cod == 88 || cod == 100 || cod == 104 || \
				cod == 120 || cod == 116))
		return (1);
	if ((op == 13) && (cod == 140 || cod == 208))
		return (1);
	if (op == 16 && cod == 64)
		return (1);
	return (0);
}

char		check_reg_nb(t_inst *inst)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (inst->type[i] == 1 && (inst->prm[i] < 1 \
					|| inst->prm[i] > REG_NUMBER))
			return (0);
		i++;
	}
	return (1);
}

void		rini_inst(t_prc *prc)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		prc->inst.type[i] = 0;
		prc->inst.prm[i] = 0;
		i++;
	}
}

void		rini_prc(t_prc *prc)
{
	prc->wait = 0;
	prc->op = 0;
	rini_inst(prc);
}
