/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruc5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 19:54:03 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/17 12:19:07 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_champ		*ft_sti2(char **tmp, t_champ *f, int l)
{
	if (tmp[2][0] == 'r')
		f = ft_reg_check(tmp[2], f, l, "sti (3rd param)");
	else if (tmp[2][0] == DIRECT_CHAR)
		f = ft_dir_check(tmp[2], f, l, "sti (3rd param)");
	else
		f = ft_inst_error("sti (3rd param)", f, l);
	ft_free_tab(tmp);
	return (f);
}

t_champ		*ft_sti(char *s, t_champ *f, int l)
{
	char	**tmp;
	int		i;

	i = 0;
	f->size += 2;
	tmp = ft_splittrim(s, SEPARATOR_CHAR);
	if (ft_tab_len(tmp) != 3 || ft_count_sep(s) != 2)
	{
		ft_free_tab(tmp);
		return (ft_inst_error("sti (too few or too many args)", f, l));
	}
	f = ft_reg_check(tmp[0], f, l, "sti (1st param)");
	if (tmp[1][0] == 'r')
		f = ft_reg_check(tmp[1], f, l, "sti (2nd param)");
	else if (ft_isind(tmp[1][0]))
		f = ft_ind_check(tmp[1], f, l, "sti (2nd param)");
	else if (tmp[1][0] == DIRECT_CHAR)
		f = ft_dir_check(tmp[1], f, l, "sti (2nd param)");
	else
		f = ft_inst_error("sti (2nd param)", f, l);
	return (ft_sti2(tmp, f, l));
}

t_champ		*ft_fork(char *s, t_champ *f, int l)
{
	char	**tmp;
	int		i;

	i = 0;
	f->size += 1;
	tmp = ft_splittrim(s, SEPARATOR_CHAR);
	if (ft_tab_len(tmp) != 1 || ft_count_sep(s) != 0)
	{
		ft_free_tab(tmp);
		return (ft_inst_error("fork (too few or too many args)", f, l));
	}
	f = ft_dir_check(tmp[0], f, l, "fork (1st param)");
	ft_free_tab(tmp);
	return (f);
}

t_champ		*ft_lld(char *s, t_champ *f, int l)
{
	char	**tmp;
	int		i;

	i = 0;
	f->size += 2;
	tmp = ft_splittrim(s, SEPARATOR_CHAR);
	if (ft_tab_len(tmp) != 2 || ft_count_sep(s) != 1)
	{
		ft_free_tab(tmp);
		return (ft_inst_error("lld (too few or too many args)", f, l));
	}
	else if (ft_isind(tmp[0][0]))
		f = ft_ind_check(tmp[0], f, l, "lld (1st param)");
	else if (tmp[0][0] == DIRECT_CHAR)
		f = ft_dir_check(tmp[0], f, l, "lld (1st param)");
	else
		f = ft_inst_error("lld (1st param)", f, l);
	f = ft_reg_check(tmp[1], f, l, "lld (2nd param)");
	ft_free_tab(tmp);
	return (f);
}

t_champ		*ft_lldi(char *s, t_champ *f, int l)
{
	char	**tmp;

	tmp = ft_splittrim(s, SEPARATOR_CHAR);
	if ((f->size += 2) && (ft_tab_len(tmp) != 3 || ft_count_sep(s) != 2))
	{
		ft_free_tab(tmp);
		return (ft_inst_error("lldi (too few or too many args)", f, l));
	}
	if (tmp[0][0] == 'r')
		f = ft_reg_check(tmp[0], f, l, "lldi (1st param)");
	else if (ft_isind(tmp[0][0]))
		f = ft_ind_check(tmp[0], f, l, "lldi (1st param)");
	else if (tmp[0][0] == DIRECT_CHAR)
		f = ft_dir_check(tmp[0], f, l, "lldi (1st param)");
	else
		f = ft_inst_error("lldi (1st param)", f, l);
	if (tmp[1][0] == 'r')
		f = ft_reg_check(tmp[1], f, l, "lldi (2nd param)");
	else if (tmp[1][0] == DIRECT_CHAR)
		f = ft_dir_check(tmp[1], f, l, "lldi (2nd param)");
	else
		f = ft_inst_error("lldi (2nd param)", f, l);
	f = ft_reg_check(tmp[2], f, l, "lldi (3rd param)");
	ft_free_tab(tmp);
	return (f);
}
