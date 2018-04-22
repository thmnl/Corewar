/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <brocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 12:54:12 by brocher           #+#    #+#             */
/*   Updated: 2018/04/20 15:26:33 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_struct.h"
#include "vm_proto.h"
#include "errors.h"
#include "libft.h"

int		ft_free_maillon(t_champ *champ, int ord, t_prc *p)
{
	t_prc *tochange;

	tochange = champ[ord].prc;
	while (tochange->next && tochange->next != p)
		tochange = tochange->next;
	if (tochange->next == p)
	{
		tochange->next = p->next;
		free(p);
		return (1);
	}
	else if (tochange == champ[ord].prc && tochange->next)
	{
		champ[ord].prc = champ[ord].prc->next;
		free(tochange);
		return (1);
	}
	return (0);
}

void	de_print_options(t_options *options)
{
	t_list *nav;

	ft_printf("dump:%d\n", options->dump);
	ft_printf("dump_cycles:%d\n", options->dump_cycles);
	ft_printf("graphic:%d\n", options->graphic);
	ft_printf("debug:%d\n", options->debug);
	ft_printf("debug_nbr:%d\n", options->debug_nbr);
	ft_printf("save:%d\n", options->save);
	ft_printf("save_nbr:%d\n", options->save_nbr);
	ft_printf("mute:%d\n", options->mute);
	nav = options->p_list;
	while (nav)
	{
		ft_printf("Path:%s\n", ((t_player*)nav->content)->path);
		ft_printf("p_nbr:%d\n", ((t_player*)nav->content)->p_nbr);
		nav = nav->next;
	}
}
