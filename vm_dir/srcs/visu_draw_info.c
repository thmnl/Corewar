/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_draw_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:41:13 by brocher           #+#    #+#             */
/*   Updated: 2018/04/16 11:52:55 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static int		check_last_live(t_vm *vm, t_visu *visu, int i)
{
	if (vm->live[i] > 0 && vm->live[i] != visu->last_live[i])
	{
		visu->last_live[i] = vm->live[i];
		visu->last_cycle[i] = vm->nb_cycles + 1;
		return (visu->last_cycle[i]);
	}
	else if (vm->live[i] == 0)
		visu->last_live[i] = 0;
	return (visu->last_cycle[i]);
}

static void		print_players(t_vm *vm, t_champ *champ, t_visu *visu)
{
	int			i;

	i = 0;
	while (i < vm->nb_champs_org)
	{
		wcolor_set(visu->info, 0, NULL);
		mvwprintw(visu->info, 18 + i * 5, 3, "Champion: ", i);
		mvwprintw(visu->info, 19 + i * 5, 5, "Id: ");
		mvwprintw
(visu->info, 20 + i * 5, 5, "Last live: %d", check_last_live(vm, visu, i));
		mvwprintw
(visu->info, 21 + i * 5, 5, "Lives in current period: %-12d", vm->live[i]);
		wcolor_set(visu->info, champ[i].color - 28, NULL);
		if (ft_strlen(champ[i].name) > 30)
			mvwprintw(visu->info, 18 + i * 5, 14, "%.28s...", champ[i].name);
		else
			mvwprintw(visu->info, 18 + i * 5, 14, "%s", champ[i].name);
		mvwprintw(visu->info, 19 + i * 5, 9, "%d", vm->id[i]);
		wcolor_set(visu->info, (champ[i].live[1] ? 5 : 6), NULL);
		i += 1;
	}
}

static void		print_some_more(t_vm *vm, WINDOW *info)
{
	wcolor_set(info, 0, NULL);
	mvwprintw(info, 6, 1, "");
	whline(info, ACS_HLINE, 48);
	mvwprintw(info, 7, 15, "%s", "- INFORMATIONS -");
	mvwprintw(info, 9, 4, "%-14s %-6d", "CYCLE_TO_DIE: ", vm->cycle_to_die);
	mvwprintw(info, 9, 29, "%-13s %-6d", "NBR_LIVE: ", NBR_LIVE);
	mvwprintw(info, 11, 4, "%-14s %-6d", "CYCLE_DELTA: ", CYCLE_DELTA);
	mvwprintw(info, 11, 29, "%-13s %-6d", "MAX_CHECKS: ", MAX_CHECKS);
	mvwprintw(info, 13, 4, "%-14s %-8d", "NB PROCESS: ", vm->nb_process);
	mvwprintw(info, 15, 1, "");
	whline(info, ACS_HLINE, 48);
	mvwprintw(info, 16, 17, "%s", "- PLAYERS -");
	mvwprintw(info, 48, 1, "");
	whline(info, ACS_HLINE, 48);
	mvwprintw(info, 49, 10, "%s", "~ It's a HEART BEAT ");
	mvwprintw(info, 50, 16, "%s", "On a HARD DRIVE ~");
}

void			draw_info(t_vm *vm, t_champ *champ, t_visu *visu)
{
	wcolor_set(visu->info, 3, NULL);
	mvwprintw(visu->info, 4, 4, "CYCLE: %-11ld", vm->nb_cycles + 1);
	mvwprintw(visu->info, 4, 29, "SPEED: %d cyc/s.%-2s", visu->pause_time, "");
	wcolor_set(visu->info, (visu->mode_pause ? 6 : 5), NULL);
	if (visu->mode_pause)
		mvwprintw(visu->info, 2, 18, "%-15s", "-  POUCE  -");
	else
		mvwprintw(visu->info, 2, 18, "%-15s", "-  FIGHT  -");
	print_some_more(vm, visu->info);
	print_players(vm, champ, visu);
	wrefresh(visu->info);
}
