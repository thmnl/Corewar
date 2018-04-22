/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <tmanuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 20:23:56 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/20 11:52:39 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_champ	*ft_init_champ(t_champ *f)
{
	f->error = 0;
	f->ligne = 0;
	f->size = 0;
	f->champ = NULL;
	f->tchamp = NULL;
	f->comment = NULL;
	f->name = NULL;
	f->labels = NULL;
	f->ist = NULL;
	return (f);
}

static t_champ	*reset_champ(t_champ *f)
{
	if (f->champ)
		ft_free_tab(f->champ);
	if (f->tchamp)
		ft_free_tab(f->tchamp);
	if (f->tchamp)
		ft_free_tab(f->ist);
	if (f->comment)
		free(f->comment);
	if (f->name)
		free(f->name);
	if (f->labels)
		free(f->labels);
	if (f->path)
		ft_strdel(&f->path);
	ft_strdel(&f->inst);
	return (ft_init_champ(f));
}

static void		ft_check_len(t_champ *f)
{
	if (f->name)
	{
		if (ft_strlen(f->name) > PROG_NAME_LENGTH)
			ft_exit("Champion name too long");
	}
	else
		ft_exit("no name");
	if (f->comment)
	{
		if (ft_strlen(f->comment) > PROG_NAME_LENGTH)
			ft_exit("Comment too long");
	}
	else
		ft_exit("no comment");
}

int				main(int ac, char **av)
{
	int		i;
	t_champ	*f;

	i = 1;
	if (ac == 1)
		ft_exit("Run asm with arg");
	if (!(f = (t_champ*)malloc(sizeof(t_champ))))
		ft_exit("Malloc failed");
	f = ft_init_champ(f);
	while (av[i])
	{
		f->path = ft_strdup(av[i]);
		f->inst = ft_strdup("live ld st add sub and or xor zjmp ldi sti \
													fork lld lldi lfork aff");
		f = ft_check_error(av[i], f);
		if (f->error)
			exit(-1);
		ft_check_len(f);
		ft_trad(f);
		f = reset_champ(f);
		i++;
	}
	free(f);
	return (0);
}
