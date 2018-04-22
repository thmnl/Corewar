/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruc6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 20:13:29 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/17 12:18:03 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_check_label(char *s, t_champ *f, int check)
{
	char	**tmp;
	int		i;
	char	*tmp2;

	i = 0;
	if (!f->labels)
		return (0);
	tmp2 = ft_strnew(ft_strlen(s));
	tmp = ft_strsplit(f->labels, ' ');
	while (s[i] && (s[i] != ' ' || s[i] != ','))
	{
		tmp2[i] = s[i];
		i++;
	}
	tmp2[i] = '\0';
	i = 0;
	while (tmp[i])
	{
		if (!ft_strcmp(tmp[i], tmp2))
			check = 1;
		i++;
	}
	ft_free_tab(tmp);
	ft_strdel(&tmp2);
	return (check);
}

int			ft_isind(char c)
{
	if (c == '-' || c == '+' || c == LABEL_CHAR || ft_isdigit(c))
		return (1);
	return (0);
}

t_champ		*ft_lfork(char *s, t_champ *f, int l)
{
	char	**tmp;
	int		i;

	i = 0;
	f->size += 1;
	tmp = ft_splittrim(s, ',');
	if (ft_tab_len(tmp) != 1 || ft_count_sep(s) != 0)
	{
		ft_free_tab(tmp);
		return (ft_inst_error("lfork (too few or too many args)", f, l));
	}
	f = ft_dir_check(tmp[0], f, l, "lfork (1st param)");
	ft_free_tab(tmp);
	return (f);
}

t_champ		*ft_aff(char *s, t_champ *f, int l)
{
	char	**tmp;
	int		i;

	f->size += 2;
	i = 0;
	tmp = ft_splittrim(s, ',');
	if (ft_tab_len(tmp) != 1)
	{
		ft_free_tab(tmp);
		return (ft_inst_error("aff (too few or too many args)", f, l));
	}
	f = ft_reg_check(tmp[0], f, l, "aff (1st param)");
	ft_free_tab(tmp);
	return (f);
}

t_champ		*ft_live(char *s, t_champ *f, int l)
{
	char	**tmp;

	f->size += 1;
	tmp = ft_splittrim(s, ',');
	if (ft_tab_len(tmp) != 1 || ft_count_sep(s) != 0)
	{
		ft_free_tab(tmp);
		return (ft_inst_error("live (too few or too many args)", f, l));
	}
	f = ft_dir_check(tmp[0], f, l, "live (1st param)");
	ft_free_tab(tmp);
	return (f);
}
