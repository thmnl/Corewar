/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:50:31 by brocher           #+#    #+#             */
/*   Updated: 2018/04/09 13:50:32 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void		colors_def(void)
{
	init_color(49, 500, 500, 500);
	init_color(50, 20, 20, 20);
	init_color(51, 950, 950, 950);
	init_color(52, 950, 150, 150);
	init_color(53, 150, 850, 150);
	init_color(54, 150, 150, 950);
	init_color(55, 950, 950, 150);
	init_color(56, 950, 550, 100);
	init_color(57, 150, 750, 850);
	init_color(58, 450, 50, 850);
	init_color(59, 750, 750, 750);
	init_color(60, 850, 1000, 1000);
	init_color(61, 1000, 950, 550);
	init_color(62, 600, 1000, 600);
	init_color(63, 1000, 550, 550);
	init_color(64, 850, 550, 1000);
	init_color(65, 550, 550, 1000);
}

static void		advanced_colors_def(void)
{
	colors_def();
	init_pair(0, 51, 50);
	init_pair(1, 50, 51);
	init_pair(2, 49, 50);
	init_pair(3, 57, 50);
	init_pair(4, 56, 50);
	init_pair(5, 53, 50);
	init_pair(6, 52, 50);
	init_pair(7, 58, 50);
	init_pair(8, 54, 50);
	init_pair(9, 50, 57);
	init_pair(10, 50, 56);
	init_pair(11, 50, 53);
	init_pair(12, 50, 52);
	init_pair(13, 50, 58);
	init_pair(14, 50, 54);
	init_pair(15, 60, 50);
	init_pair(16, 61, 50);
	init_pair(17, 62, 50);
	init_pair(18, 63, 50);
	init_pair(19, 64, 50);
	init_pair(20, 65, 50);
	init_pair(21, 55, 50);
}

static void		basic_colors_def(void)
{
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_GREEN, COLOR_BLACK);
	init_pair(6, COLOR_RED, COLOR_BLACK);
	init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(8, COLOR_BLUE, COLOR_BLACK);
	init_pair(9, COLOR_BLACK, COLOR_CYAN);
	init_pair(10, COLOR_BLACK, COLOR_YELLOW);
	init_pair(11, COLOR_BLACK, COLOR_GREEN);
	init_pair(12, COLOR_BLACK, COLOR_RED);
	init_pair(13, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(14, COLOR_BLACK, COLOR_BLUE);
	init_pair(15, COLOR_YELLOW, COLOR_BLACK);
}

static void		handle_colors(t_visu *visu)
{
	start_color();
	use_default_colors();
	if (visu->color_mode)
		advanced_colors_def();
	else
		basic_colors_def();
}

t_visu			*visu_init(t_champ *champ, int nb)
{
	t_visu		*new;

	initscr();
	cbreak();
	noecho();
	curs_set(0);
	nodelay(stdscr, 1);
	refresh();
	new = NULL;
	new = (t_visu *)safe_malloc(sizeof(t_visu));
	new->memory = NULL;
	new->info = NULL;
	new->term_wid = COLS;
	new->term_hei = LINES;
	new->color_mode = can_change_color();
	new->mem_line_size = 0;
	new->mode_pause = 1;
	new->pause_time = 20;
	new->time_sequence = 0;
	new->last_live = init_last_live();
	new->last_cycle = init_last_live();
	process_names(champ, nb, 0, 0);
	handle_colors(new);
	return (new);
}
