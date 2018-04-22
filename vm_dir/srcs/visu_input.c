/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <brocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:50:52 by brocher           #+#    #+#             */
/*   Updated: 2018/04/20 11:50:15 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void		handle_pause(t_visu *visu)
{
	if (visu->mode_pause)
		visu->mode_pause = 0;
	else
		visu->mode_pause = 1;
}

static void		set_speed(t_visu *visu, int key)
{
	if (key == '*')
		visu->pause_time = 1000;
	if (key == '-')
		visu->pause_time -= 5;
	else
		visu->pause_time += 5;
	if (visu->pause_time > 1000)
		visu->pause_time = 1000;
	if (visu->pause_time < 5)
		visu->pause_time = 5;
}

int				wait_for_input(t_visu *visu, int key)
{
	key = getch();
	if (!visu->mode_pause && key == ERR)
	{
		visu->time_sequence += usleep(1000000 / visu->pause_time);
		visu->time_sequence += 1000000 / visu->pause_time;
	}
	else
	{
		usleep(5000);
		visu->time_sequence += 5000;
	}
	mvprintw(LINES - 2, 2, "Pressed key: %-5d", key);
	if (key == 'q')
		return (0);
	if (key == 'p')
		handle_pause(visu);
	if (key == '+' || key == '-' || key == '*')
		set_speed(visu, key);
	if (!visu->mode_pause && key == ERR)
		return (32);
	return (key);
}
