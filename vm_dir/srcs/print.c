/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:36:31 by brocher           #+#    #+#             */
/*   Updated: 2018/04/09 13:36:33 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_struct.h"
#include "vm_proto.h"
#include "errors.h"

static void		print_name_pc(int nb, t_champ *champ)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		ft_printf("Player %d : \e[%d;m%s\e[0;m\n", champ[i].id, \
				champ[i].color, champ[i].name);
		i++;
	}
}

static char		check_pc(t_champ *champ, int nb, int pos)
{
	int		i;
	t_prc	*prc;

	i = 0;
	while (i < nb)
	{
		prc = champ[i].prc;
		while (prc != NULL)
		{
			if (prc->pc == pos)
				return (1);
			prc = prc->next;
		}
		i++;
	}
	return (0);
}

void			print_middle_char(t_vm vm, t_champ *champ, int i)
{
	if (vm.color[i] != 0)
	{
		if (check_pc(champ, vm.nb_champs_org, i))
			ft_printf("\e[%d;47m", vm.color[i]);
		else
			ft_printf("\e[%d;m", vm.color[i]);
		if (vm.highlight[i] != 0)
			ft_printf("\e[1;m");
	}
	ft_printf("%.2hx ", (unsigned char)vm.arn[i]);
	ft_printf("\e[0;0m");
}

void			print_eol_char(t_vm vm, t_champ *champ, int i)
{
	if (vm.color[i] != 0)
	{
		if (check_pc(champ, vm.nb_champs_org, i))
			ft_printf("\e[%d;47m", vm.color[i]);
		else
			ft_printf("\e[%d;m", vm.color[i]);
		if (vm.highlight[i] != 0)
			ft_printf("\e[1;m");
	}
	ft_printf("%.2hx", (unsigned char)vm.arn[i]);
	ft_printf("\e[0;0m\n");
}

void			print_arena(t_vm vm, t_champ *champ)
{
	int		i;
	int		cl;

	i = 0;
	print_name_pc(vm.nb_champs, champ);
	ft_printf("nb of cycles : %ld\n", vm.nb_cycles);
	while (i < MEM_SIZE)
	{
		cl = 0;
		while (cl < 63)
		{
			print_middle_char(vm, champ, i);
			i++;
			cl++;
		}
		if (i < MEM_SIZE)
			print_eol_char(vm, champ, i);
		i++;
	}
	ft_printf("\n");
}
