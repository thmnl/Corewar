/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:50:13 by brocher           #+#    #+#             */
/*   Updated: 2018/04/09 13:50:15 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void		create_windows(t_visu *visu)
{
	if (!visu->info)
	{
		visu->info = newwin(66, 50, 0, 0);
	}
	if (!visu->memory)
	{
		if (COLS > 50 + 64 * 3 + 3)
		{
			visu->memory = newwin(66, 64 * 3 + 3, 0, 50);
			visu->mem_line_size = 64;
		}
		else if (COLS > 50 + 15)
		{
			visu->memory = newwin(66, COLS - 51, 0, 50);
			visu->mem_line_size = ((COLS - 50) / 3) - 1;
		}
	}
}

static void		check_and_destroy_wins(t_visu *visu)
{
	if (visu->memory && (COLS != visu->term_wid || LINES != visu->term_hei))
	{
		wclear(visu->memory);
		wrefresh(visu->memory);
		delwin(visu->memory);
		visu->memory = NULL;
	}
	if (visu->info && (COLS != visu->term_wid || LINES != visu->term_hei))
	{
		wclear(visu->info);
		wrefresh(visu->info);
		delwin(visu->info);
		visu->info = NULL;
	}
	visu->term_wid = COLS;
	visu->term_hei = LINES;
}

int				handle_ncurses(t_vm *vm, t_champ *champ, t_visu *visu)
{
	int			input;

	while (1)
	{
		if (COLS != visu->term_wid || LINES != visu->term_hei)
			check_and_destroy_wins(visu);
		if (!visu->info || !visu->memory)
			create_windows(visu);
		draw_windows(vm, champ, visu);
		if (!(input = wait_for_input(visu, 0)))
			return (0);
		else if (input == 32)
			break ;
	}
	return (1);
}
