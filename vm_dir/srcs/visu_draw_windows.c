/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_draw_windows.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <brocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:41:27 by brocher           #+#    #+#             */
/*   Updated: 2018/04/20 11:45:09 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static char		check_pc(t_champ *champ, int nb, int pos)
{
	int		i;
	t_prc	*prc;

	i = 0;
	while (i < nb)
	{
		prc = champ[i].prc;
		if (prc->live == -1)
			return (0);
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

static void		set_the_right_color
	(t_vm *vm, t_champ *champ, t_visu *visu, int i)
{
	wcolor_set(visu->memory, 2, NULL);
	if (vm->color[i] != 0)
	{
		if (check_pc(champ, vm->nb_champs_org, i))
			wcolor_set(visu->memory, vm->color[i] - 22, NULL);
		else
		{
			wcolor_set(visu->memory, vm->color[i] - 28, NULL);
			if (vm->highlight[i])
			{
				if (visu->color_mode)
					wcolor_set(visu->memory, vm->color[i] - 16, NULL);
				else
					wattron(visu->memory, A_BOLD);
			}
		}
	}
	else if (vm->color[i] == 0 && check_pc(champ, vm->nb_champs_org, i))
		wcolor_set(visu->memory, 1, NULL);
}

static void		draw_memory(t_vm *vm, t_champ *champ, t_visu *visu)
{
	int			ln;
	int			cl;
	int			i;

	ln = 0;
	i = 0;
	while (ln < MEM_SIZE / visu->mem_line_size)
	{
		cl = 0;
		mvwprintw(visu->memory, ln + 1, cl + 2, "");
		while (i < MEM_SIZE && cl < visu->mem_line_size)
		{
			set_the_right_color(vm, champ, visu, i);
			wprintw(visu->memory, "%.2hhx", vm->arn[i]);
			wcolor_set(visu->memory, 0, NULL);
			wattroff(visu->memory, A_BOLD);
			wprintw(visu->memory, " ");
			cl += 1;
			i += 1;
		}
		ln += 1;
	}
}

static void		handle_hearth(t_vm *vm, t_champ *champ, t_visu *visu)
{
	clean_heart_space(visu);
	set_color_again(vm, champ, visu);
	if (visu->time_sequence >= 1000000)
		visu->time_sequence = 0;
	else if (visu->time_sequence >= 875000)
		print_the_heart_3(visu, 8);
	else if (visu->time_sequence >= 750000)
		print_the_heart_4(visu, 7);
	else if (visu->time_sequence >= 625000)
		print_the_heart_3(visu, 6);
	else if (visu->time_sequence >= 500000)
		print_the_heart_2(visu, 5);
	else if (visu->time_sequence >= 375000)
		print_the_heart_2(visu, 4);
	else if (visu->time_sequence >= 250000)
		print_the_heart_1(visu, 3);
	else if (visu->time_sequence >= 125000)
		print_the_heart_1(visu, 2);
	else
		print_the_heart_1(visu, 1);
}

void			draw_windows(t_vm *vm, t_champ *champ, t_visu *visu)
{
	wcolor_set(visu->memory, 1, NULL);
	wborder(visu->memory, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	draw_memory(vm, champ, visu);
	wrefresh(visu->memory);
	wcolor_set(visu->info, 1, NULL);
	wborder(visu->info, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	draw_info(vm, champ, visu);
	handle_hearth(vm, champ, visu);
	wrefresh(visu->info);
}
