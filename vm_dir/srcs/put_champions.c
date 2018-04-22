/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_champions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:37:53 by brocher           #+#    #+#             */
/*   Updated: 2018/04/09 13:37:55 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_struct.h"
#include "vm_proto.h"
#include "errors.h"

void		dump_memory(t_vm vm)
{
	int		i;
	int		cl;

	i = 0;
	while (i < MEM_SIZE)
	{
		cl = 0;
		if (i == 0)
			ft_printf("0x0000 : ");
		else
			ft_printf("%#.4x : ", i);
		while (cl < 63)
		{
			ft_printf("%.2hx ", (unsigned char)vm.arn[i]);
			i++;
			cl++;
		}
		if (i < MEM_SIZE)
		{
			ft_printf("%.2hx \n", (unsigned char)vm.arn[i]);
		}
		i++;
	}
}

void		put_champion(t_vm *vm, t_champ *champ, int ord, int tot)
{
	int		i;

	i = 0;
	while (i < champ[ord].size)
	{
		put_in_arena(vm, tot + i, champ[ord].inst[i]);
		put_in_color(vm, tot + i, champ[ord].color);
		i++;
	}
	first_process(&(champ[ord]), tot);
	free(champ[ord].inst);
}

void		ini_arena(t_vm *vm, t_champ *champ)
{
	int		diff;
	int		tot;
	int		i;

	ft_memset(vm->arn, 0, MEM_SIZE);
	ft_memset(vm->color, 0, MEM_SIZE);
	ft_memset(vm->highlight, 0, MEM_SIZE);
	if (CHAMP_MAX_SIZE >= MEM_SIZE)
		error("champion size is too big", NULL);
	if ((diff = MEM_SIZE / vm->nb_champs_org) < CHAMP_MAX_SIZE)
		error("champions are overlapping", NULL);
	i = 0;
	tot = 0;
	while (i < vm->nb_champs_org)
	{
		put_champion(vm, champ, i, tot);
		i++;
		tot += diff;
	}
}

long int	dump_max_cycle(t_options *opt)
{
	if (!opt->dump)
		return (LONG_MAX);
	return ((long int)opt->dump_cycles);
}

void		ini_vm(t_vm *vm, t_options *opt)
{
	int		i;

	vm->nb_champs_org = opt->nbr_champs;
	vm->nb_champs = vm->nb_champs_org;
	vm->nb_cycles = 0;
	vm->live = (int *)safe_malloc(sizeof(int) * vm->nb_champs);
	vm->id = (int *)safe_malloc(sizeof(int) * vm->nb_champs);
	vm->option = opt;
	i = 0;
	while (i < vm->nb_champs)
		vm->live[i++] = 0;
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->cycle_new = 0;
	vm->check_new = 0;
	vm->nb_process = 0;
	vm->nb_cycle_max = dump_max_cycle(opt);
	i = 0;
	while (i < MEM_SIZE)
		vm->arn[(i++) % MEM_SIZE] = 0;
}
