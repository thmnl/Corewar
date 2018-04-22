/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruc2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 18:03:57 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/17 11:40:45 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_tab_len(char **t)
{
	int i;

	i = 0;
	if (!t)
		return (0);
	while (t[i])
		i++;
	return (i);
}

t_champ		*ft_ld(char *s, t_champ *f, int l)
{
	char	**tmp;
	int		i;

	i = 0;
	f->size += 2;
	tmp = ft_splittrim(s, SEPARATOR_CHAR);
	if (ft_tab_len(tmp) != 2 || ft_count_sep(s) != 1)
	{
		ft_free_tab(tmp);
		return (ft_inst_error("ld (too few or too many args)", f, l));
	}
	if (tmp[0][0] == DIRECT_CHAR)
		f = ft_dir_check(tmp[0], f, l, "ld (1st param)");
	else if (ft_isind(tmp[0][0]))
		f = ft_ind_check(tmp[0], f, l, "ld (1st param)");
	else
		ft_inst_error("ld (1st param)", f, l);
	f = ft_reg_check(tmp[1], f, l, "ld (2nd param)");
	ft_free_tab(tmp);
	return (f);
}

t_champ		*ft_st(char *s, t_champ *f, int l)
{
	char	**tmp;
	int		i;

	i = 0;
	f->size += 2;
	tmp = ft_splittrim(s, SEPARATOR_CHAR);
	if (ft_tab_len(tmp) != 2 || ft_count_sep(s) != 1)
	{
		ft_free_tab(tmp);
		return (ft_inst_error("st (too few or too many args)", f, l));
	}
	f = ft_reg_check(tmp[0], f, l, "st (1st param)");
	if (tmp[1][0] == 'r')
		f = ft_reg_check(tmp[1], f, l, "st (2nd param)");
	else if (ft_isind(tmp[1][0]))
		f = ft_ind_check(tmp[1], f, l, "st (2nd param)");
	else
		ft_inst_error("st (2nd param)", f, l);
	ft_free_tab(tmp);
	return (f);
}

t_champ		*ft_add(char *s, t_champ *f, int l)
{
	char	**tmp;
	int		i;

	i = 0;
	f->size += 2;
	tmp = ft_splittrim(s, SEPARATOR_CHAR);
	if (ft_tab_len(tmp) != 3 || ft_count_sep(s) != 2)
	{
		ft_free_tab(tmp);
		return (ft_inst_error("add (too few or too many args)", f, l));
	}
	f = ft_reg_check(tmp[0], f, l, "add (1st param)");
	f = ft_reg_check(tmp[1], f, l, "add (2nd param)");
	f = ft_reg_check(tmp[2], f, l, "add (3rd param)");
	ft_free_tab(tmp);
	return (f);
}

t_champ		*ft_sub(char *s, t_champ *f, int l)
{
	char	**tmp;
	int		i;

	i = 0;
	f->size += 2;
	tmp = ft_splittrim(s, SEPARATOR_CHAR);
	if (ft_tab_len(tmp) != 3 || ft_count_sep(s) != 2)
	{
		ft_free_tab(tmp);
		return (ft_inst_error("sub (too few or too many args)", f, l));
	}
	f = ft_reg_check(tmp[0], f, l, "sub (1st param)");
	f = ft_reg_check(tmp[1], f, l, "sub (2nd param)");
	f = ft_reg_check(tmp[2], f, l, "sub (3rd param)");
	ft_free_tab(tmp);
	return (f);
}
