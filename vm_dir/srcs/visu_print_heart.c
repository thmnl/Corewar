/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_print_heart.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <brocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:51:06 by brocher           #+#    #+#             */
/*   Updated: 2018/04/20 11:19:21 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void			print_the_heart_1(t_visu *visu, int phase)
{
	if (phase == 1)
		mvwprintw(visu->info, 58, 23, "  ");
	else if (phase == 2)
	{
		mvwprintw(visu->info, 57, 21, "  ");
		mvwprintw(visu->info, 57, 25, "  ");
		mvwprintw(visu->info, 58, 21, "      ");
		mvwprintw(visu->info, 59, 23, "  ");
	}
	else if (phase == 3)
	{
		mvwprintw(visu->info, 56, 21, "  ");
		mvwprintw(visu->info, 56, 25, "  ");
		mvwprintw(visu->info, 57, 19, "          ");
		mvwprintw(visu->info, 58, 21, "      ");
		mvwprintw(visu->info, 59, 23, "  ");
	}
}

void			print_the_heart_2(t_visu *visu, int phase)
{
	if (phase == 4)
	{
		mvwprintw(visu->info, 55, 19, "    ");
		mvwprintw(visu->info, 55, 25, "    ");
		mvwprintw(visu->info, 56, 17, "              ");
		mvwprintw(visu->info, 57, 17, "              ");
		mvwprintw(visu->info, 58, 19, "          ");
		mvwprintw(visu->info, 59, 21, "      ");
		mvwprintw(visu->info, 60, 23, "  ");
	}
	else if (phase == 5)
	{
		mvwprintw(visu->info, 55, 19, "    ");
		mvwprintw(visu->info, 55, 25, "    ");
		mvwprintw(visu->info, 56, 17, "              ");
		mvwprintw(visu->info, 57, 17, "              ");
		mvwprintw(visu->info, 58, 19, "    ");
		mvwprintw(visu->info, 58, 25, "    ");
		mvwprintw(visu->info, 59, 21, "      ");
		mvwprintw(visu->info, 60, 23, "  ");
	}
}

void			print_the_heart_3(t_visu *visu, int phase)
{
	if (phase == 6)
	{
		mvwprintw(visu->info, 55, 19, "    ");
		mvwprintw(visu->info, 55, 25, "    ");
		mvwprintw(visu->info, 56, 17, "    ");
		mvwprintw(visu->info, 56, 23, "  ");
		mvwprintw(visu->info, 56, 27, "    ");
		mvwprintw(visu->info, 57, 17, "    ");
		mvwprintw(visu->info, 57, 27, "    ");
		mvwprintw(visu->info, 58, 19, "    ");
		mvwprintw(visu->info, 58, 25, "    ");
		mvwprintw(visu->info, 59, 21, "      ");
		mvwprintw(visu->info, 60, 23, "  ");
	}
	else if (phase == 8)
	{
		mvwprintw(visu->info, 55, 19, "  ");
		mvwprintw(visu->info, 55, 27, "  ");
		mvwprintw(visu->info, 56, 23, "  ");
		mvwprintw(visu->info, 57, 17, "  ");
		mvwprintw(visu->info, 57, 29, "  ");
		mvwprintw(visu->info, 59, 21, "  ");
		mvwprintw(visu->info, 59, 25, "  ");
	}
}

void			print_the_heart_4(t_visu *visu, int phase)
{
	if (phase == 7)
	{
		mvwprintw(visu->info, 55, 19, "    ");
		mvwprintw(visu->info, 55, 25, "    ");
		mvwprintw(visu->info, 56, 17, "  ");
		mvwprintw(visu->info, 56, 23, "  ");
		mvwprintw(visu->info, 56, 29, "  ");
		mvwprintw(visu->info, 57, 17, "  ");
		mvwprintw(visu->info, 57, 29, "  ");
		mvwprintw(visu->info, 58, 19, "  ");
		mvwprintw(visu->info, 58, 27, "  ");
		mvwprintw(visu->info, 59, 21, "  ");
		mvwprintw(visu->info, 59, 25, "  ");
		mvwprintw(visu->info, 60, 23, "  ");
	}
}
