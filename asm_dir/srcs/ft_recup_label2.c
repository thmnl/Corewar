/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recup_label2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 00:47:37 by allallem          #+#    #+#             */
/*   Updated: 2018/04/19 19:07:02 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_free_label(t_champ *p)
{
	int i;

	i = 0;
	if (!p->label)
		return ;
	while (p->label[i])
	{
		ft_strdel(&p->label[i]->name);
		free(p->label[i]);
		i++;
	}
	free(p->label);
}

char	**ft_trim(char **tab)
{
	int		i;
	char	*freeme;

	freeme = NULL;
	i = 0;
	while (tab[i])
	{
		freeme = tab[i];
		tab[i] = ft_strtrim(tab[i]);
		free(freeme);
		i++;
	}
	return (tab);
}

int		ft_jump_pattern(char *str)
{
	int i;

	i = 0;
	if (ft_check_ist(str))
	{
		while (str[i] != ':')
			i++;
	}
	if (str[i] == ' ')
		i++;
	while (str[i] != ' ')
		i++;
	return (i);
}

int		ft_count_label_char(char *str, int order)
{
	int i;

	i = 0;
	while (str[i] && str[i] != ':')
		i++;
	if (order == 0)
		return (i);
	while (str[i] && (str[i] == ':' || str[i] == ' '))
		i++;
	return (i);
}
