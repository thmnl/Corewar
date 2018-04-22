/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruc4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <tmanuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 19:31:10 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/18 11:32:30 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_champ		*ft_xor2(char **tmp, t_champ *f, int l)
{
	if (tmp[1][0] == 'r')
		f = ft_reg_check(tmp[1], f, l, "xor (2nd param)");
	else if (ft_isind(tmp[1][0]))
		f = ft_ind_check(tmp[1], f, l, "xor (2nd param)");
	else if (tmp[1][0] == DIRECT_CHAR)
		f = ft_dir_check(tmp[1], f, l, "xor (2nd param)");
	else
		f = ft_inst_error("xor (2nd param)", f, l);
	f = ft_reg_check(tmp[2], f, l, "xor (3rd param)");
	ft_free_tab(tmp);
	return (f);
}

t_champ		*ft_xor(char *s, t_champ *f, int l)
{
	char	**tmp;
	int		i;

	i = 0;
	f->size += 2;
	tmp = ft_splittrim(s, SEPARATOR_CHAR);
	if (ft_tab_len(tmp) != 3 || ft_count_sep(s) != 2)
	{
		ft_free_tab(tmp);
		return (ft_inst_error("xor (too few or too many args)", f, l));
	}
	if (tmp[0][0] == 'r')
		f = ft_reg_check(tmp[0], f, l, "xor (1st param)");
	else if (ft_isind(tmp[0][0]))
		f = ft_ind_check(tmp[0], f, l, "xor (1st param)");
	else if (tmp[0][0] == DIRECT_CHAR)
		f = ft_dir_check(tmp[0], f, l, "xor (1st param)");
	else
		f = ft_inst_error("xor (1st param)", f, l);
	return (ft_xor2(tmp, f, l));
}

t_champ		*ft_zjmp(char *s, t_champ *f, int l)
{
	char	**tmp;
	int		i;

	i = 0;
	f->size += 1;
	tmp = ft_splittrim(s, SEPARATOR_CHAR);
	if (ft_tab_len(tmp) != 1 || ft_count_sep(s) != 0)
	{
		ft_free_tab(tmp);
		return (ft_inst_error("zjmp (too few or too many args)", f, l));
	}
	f = ft_dir_check(tmp[0], f, l, "zjmp (1st param)");
	ft_free_tab(tmp);
	return (f);
}

t_champ		*ft_ldi2(char **tmp, t_champ *f, int l)
{
	if (tmp[1][0] == 'r')
		f = ft_reg_check(tmp[1], f, l, "ldi (2nd param)");
	else if (tmp[1][0] == DIRECT_CHAR)
		f = ft_dir_check(tmp[1], f, l, "ldi (2nd param)");
	else
		f = ft_inst_error("ldi (2nd param)", f, l);
	f = ft_reg_check(tmp[2], f, l, "ldi (3rd param)");
	ft_free_tab(tmp);
	return (f);
}

t_champ		*ft_ldi(char *s, t_champ *f, int l)
{
	char	**tmp;
	int		i;

	i = 0;
	f->size += 2;
	tmp = ft_splittrim(s, SEPARATOR_CHAR);
	if (ft_tab_len(tmp) != 3 || ft_count_sep(s) != 2)
	{
		ft_free_tab(tmp);
		return (ft_inst_error("ldi (too few or too many args)", f, l));
	}
	if (tmp[0][0] == 'r')
		f = ft_reg_check(tmp[0], f, l, "ldi (1st param)");
	else if (ft_isind(tmp[0][0]))
		f = ft_ind_check(tmp[0], f, l, "ldi (1st param)");
	else if (tmp[0][0] == DIRECT_CHAR)
		f = ft_dir_check(tmp[0], f, l, "ldi (1st param)");
	else
		f = ft_inst_error("ldi (1st param)", f, l);
	return (ft_ldi2(tmp, f, l));
}
