/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <brocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 12:54:02 by brocher           #+#    #+#             */
/*   Updated: 2018/04/20 13:54:11 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_struct.h"
#include "vm_proto.h"
#include "errors.h"
#include "visu.h"
#include <limits.h>

void	kill_process(t_vm *vm, t_champ *champ)
{
	int		ord;
	t_prc	*tmp;

	ord = 0;
	while (ord < vm->nb_champs_org)
	{
		tmp = champ[ord].prc;
		while (tmp != NULL)
		{
			if (tmp->live == 0)
				tmp->live = -1;
			else if (tmp->live == 1)
				tmp->live = 0;
			tmp = tmp->next;
		}
		ord++;
	}
}

void	check_live(t_vm *vm, t_champ *champ)
{
	int		i;

	i = 0;
	while (i < vm->nb_champs_org)
	{
		champ[i].live[0] = champ[i].live[1];
		if ((vm->live)[i] <= 0)
		{
			champ[i].live[1] = 0;
			(vm->live)[i] = -1;
			(vm->nb_champs)--;
		}
		else
		{
			if (champ[i].live[0] == 0)
				champ[i].live[1] = 0;
			else
				champ[i].live[1] = 1;
		}
		i++;
	}
	kill_process(vm, champ);
	vm->nb_process = count_process(vm, champ);
}

int		nb_lives(t_vm *vm)
{
	int		tot;
	int		i;

	tot = 0;
	i = 0;
	while (i < vm->nb_champs_org)
	{
		if ((vm->live)[i] != -1)
		{
			tot += (vm->live)[i];
			vm->live[i] = 0;
		}
		i++;
	}
	return (tot);
}

char	check_cycle(t_vm *vm, t_champ *champ)
{
	if (vm->option->save && vm->nb_cycles == vm->option->save_nbr)
		dump_memory(*vm);
	if (vm->nb_cycles >= vm->nb_cycle_max || vm->nb_cycles == LONG_MAX)
	{
		dump_memory(*vm);
		return (0);
	}
	if (vm->cycle_new == vm->cycle_to_die)
	{
		check_live(vm, champ);
		if (vm->nb_process == 0)
			return (0);
		(vm->check_new)++;
		if (nb_lives(vm) >= NBR_LIVE || vm->check_new == MAX_CHECKS)
		{
			vm->cycle_to_die -= CYCLE_DELTA;
			if (vm->cycle_to_die <= 0)
				return (0);
			vm->check_new = 0;
		}
		vm->cycle_new = 0;
	}
	return (1);
}
