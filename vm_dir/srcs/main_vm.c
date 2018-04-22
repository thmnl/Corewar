/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 12:56:33 by brocher           #+#    #+#             */
/*   Updated: 2018/04/20 15:34:01 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_struct.h"
#include "vm_proto.h"
#include "errors.h"
#include "visu.h"
#include <limits.h>

void		order_champs(t_vm *vm, t_champ *champ)
{
	int		i;
	t_champ tmp;

	i = 1;
	while (i < vm->nb_champs_org)
	{
		if (champ[i - 1].id < champ[i].id)
		{
			tmp = champ[i - 1];
			champ[i - 1] = champ[i];
			champ[i] = tmp;
			i = 0;
		}
		i++;
	}
	i = 0;
	while (i < vm->nb_champs_org)
	{
		vm->id[i] = champ[i].id;
		i++;
	}
}

void		introduce_champs(t_vm vm, t_champ *champ)
{
	int		i;

	ft_printf("Introducing contestants...\n");
	i = 0;
	while (i < vm.nb_champs_org)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n"\
				, champ[i].id, champ[i].size, champ[i].name, champ[i].comment);
		i++;
	}
}

void		last_free(t_vm vm, t_champ *champ, t_options *options)
{
	int		i;
	t_prc	*tmp;

	i = 0;
	free(vm.live);
	free(vm.id);
	while (i < vm.nb_champs_org)
	{
		while (champ[i].prc != NULL)
		{
			tmp = champ[i].prc;
			champ[i].prc = champ[i].prc->next;
			free(tmp);
		}
		free(champ[i].comment);
		free(champ[i].name);
		i++;
	}
	free(champ);
	del_options(options);
}

int			main(int ac, char **av)
{
	t_vm		vm;
	t_champ		*champ;
	t_options	*options;

	if (ac < 2)
		usage();
	options = init_options();
	load_options(ac, av, options);
	champ = ini_champ_id(options);
	ini_vm(&vm, options);
	read_analyze(champ, options);
	order_champs(&vm, champ);
	ini_arena(&vm, champ);
	introduce_champs(vm, champ);
	begin_war(&vm, champ);
	last_free(vm, champ, options);
	return (0);
}
