/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:39:05 by brocher           #+#    #+#             */
/*   Updated: 2018/04/09 13:39:07 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_struct.h"
#include "vm_proto.h"
#include "errors.h"
#include "libft.h"

t_options	*init_options(void)
{
	t_options *new;

	new = (t_options*)safe_malloc(sizeof(t_options));
	new->dump = 0;
	new->dump_cycles = 0;
	new->graphic = 0;
	new->p_list = NULL;
	new->nbr_champs = 0;
	new->debug = 0;
	new->debug_nbr = 0;
	new->save = 0;
	new->save_nbr = 0;
	new->mute = 0;
	return (new);
}

void		del_options(t_options *options)
{
	t_list	*nav;
	t_list	*todel;

	nav = options->p_list;
	while (nav)
	{
		todel = nav;
		nav = nav->next;
		free(todel->content);
		free(todel);
	}
	free(options);
}

static void	sft_check_duplicate(int p_nbr, t_list *p_list, char *name)
{
	if (!p_nbr)
		return ;
	while (p_list)
	{
		if (((t_player*)p_list->content)->p_nbr == p_nbr)
			error("duplicate player number", name);
		p_list = p_list->next;
	}
}

void		options_add_player(char *str, int p_nbr, t_options *opt)
{
	size_t		strlen;
	t_player	*player;
	t_list		*new;

	sft_check_duplicate(p_nbr, opt->p_list, str);
	strlen = ft_strlen(str);
	if (strlen < 5 || str[strlen - 1] != 'r' || str[strlen - 2] != 'o' ||
		str[strlen - 3] != 'c' || str[strlen - 4] != '.')
	{
		error("Invalid file:", str);
	}
	player = (t_player*)safe_malloc(sizeof(t_player));
	player->path = str;
	player->p_nbr = p_nbr;
	new = ft_lstnew_ref((void*)player, sizeof(t_player));
	ft_lstaddend(&opt->p_list, new);
}
