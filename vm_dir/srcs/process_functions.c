/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:37:10 by brocher           #+#    #+#             */
/*   Updated: 2018/04/09 13:37:12 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_struct.h"
#include "vm_proto.h"
#include "errors.h"

void		move_pc(t_prc *prc, t_op *op_tab)
{
	int		tot;

	tot = op_tab[prc->op - 1].encoding + 1;
	tot += prc->inst.type[0] - (op_tab[prc->op - 1].size == 1 \
			&& prc->inst.type[0] == 4) * 2;
	tot += prc->inst.type[1] - (op_tab[prc->op - 1].size == 1 \
			&& prc->inst.type[1] == 4) * 2;
	tot += prc->inst.type[2] - (op_tab[prc->op - 1].size == 1 \
			&& prc->inst.type[2] == 4) * 2;
	prc->pc += tot;
}

int			count_process(t_vm *vm, t_champ *champ)
{
	int		i;
	t_prc	*prc;
	int		tot;

	i = 0;
	tot = 0;
	while (i < vm->nb_champs_org)
	{
		prc = champ[i].prc;
		while (prc != NULL)
		{
			if (prc->live >= 0)
				tot++;
			prc = prc->next;
		}
		i++;
	}
	return (tot);
}

void		first_process(t_champ *champ, int pc)
{
	champ->prc = (t_prc *)safe_malloc(sizeof(t_prc));
	champ->prc->pc = pc;
	ft_memset(champ->prc->reg, 0, REG_NUMBER * REG_SIZE);
	put_in_reg(champ->prc, 1, champ->id);
	champ->prc->carry = 0;
	champ->prc->next = NULL;
	rini_inst(champ->prc);
	champ->prc->op = 0;
	champ->prc->wait = 0;
	champ->prc->live = 0;
}
