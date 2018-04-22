/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_addendum_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:41:00 by brocher           #+#    #+#             */
/*   Updated: 2018/04/09 13:41:02 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void			process_names(t_champ *champ, int nb, int i, int j)
{
	while (i < nb)
	{
		j = 0;
		while (champ[i].name[j])
		{
			if (champ[i].name[j] == '\n')
				champ[i].name[j] = ' ';
			j += 1;
		}
		i += 1;
	}
}

int				*init_last_live(void)
{
	int			*tab;
	int			i;

	tab = NULL;
	tab = (int *)safe_malloc(sizeof(int) * MAX_PLAYERS);
	i = 0;
	while (i < MAX_PLAYERS)
	{
		tab[i] = 0;
		i += 1;
	}
	return (tab);
}

void			clean_heart_space(t_visu *visu)
{
	int			i;

	i = 0;
	while (i < 12)
	{
		mvwprintw(visu->info, 51 + i, 5, "%40s", "");
		i += 1;
	}
}

void			set_color_again(t_vm *vm, t_champ *champ, t_visu *visu)
{
	int			most_lives;
	int			max;
	int			i;

	wcolor_set(visu->info, 1, NULL);
	max = vm->nb_champs_org;
	i = 0;
	most_lives = 0;
	while (i < max)
	{
		if (most_lives <= vm->live[i])
		{
			wcolor_set(visu->info, champ[i].color - 22, NULL);
			most_lives = vm->live[i];
		}
		i += 1;
	}
}
