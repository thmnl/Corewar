/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champs_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 12:53:26 by brocher           #+#    #+#             */
/*   Updated: 2018/04/09 12:53:28 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_struct.h"
#include "vm_proto.h"
#include "errors.h"

static int	sft_is_duplicate(t_champ *champ_array, int id, int nbr_champs)
{
	int	i;

	i = 0;
	while (i < nbr_champs)
	{
		if (id == champ_array[i].id)
			return (1);
		i++;
	}
	return (0);
}

static void	sft_fill_champ_id_color(t_champ *champ_array, t_options *opt)
{
	t_list	*nav;
	int		i;
	int		id;

	i = 0;
	nav = opt->p_list;
	while (nav && i < opt->nbr_champs)
	{
		champ_array[i].color = 31 + i;
		champ_array[i++].id = ((t_player*)nav->content)->p_nbr;
		nav = nav->next;
	}
	i = -1;
	id = -1;
	while (++i < opt->nbr_champs)
	{
		if (champ_array[i].id == 0)
		{
			while (sft_is_duplicate(champ_array, id, opt->nbr_champs))
				id--;
			champ_array[i].id = id;
		}
	}
}

t_champ		*ini_champ_id(t_options *opt)
{
	t_champ	*champ;
	int		i;

	champ = (t_champ *)safe_malloc(sizeof(t_champ) * opt->nbr_champs);
	i = 0;
	while (i < opt->nbr_champs)
		champ[i++].id = 0;
	sft_fill_champ_id_color(champ, opt);
	return (champ);
}
