/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruc3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 19:17:37 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/17 11:43:12 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_champ		*ft_and2(char **tmp, t_champ *f, int l)
{
	if (tmp[1][0] == 'r')
		f = ft_reg_check(tmp[1], f, l, "and (2nd param)");
	else if (ft_isind(tmp[1][0]))
		f = ft_ind_check(tmp[1], f, l, "and (2nd param)");
	else if (tmp[1][0] == DIRECT_CHAR)
		f = ft_dir_check(tmp[1], f, l, "and (2nd param)");
	else
		f = ft_inst_error("and (2nd param)", f, l);
	f = ft_reg_check(tmp[2], f, l, "and (3rd param)");
	ft_free_tab(tmp);
	return (f);
}

t_champ		*ft_and(char *s, t_champ *f, int l)
{
	char	**tmp;
	int		i;

	f->size += 2;
	i = 0;
	tmp = ft_splittrim(s, SEPARATOR_CHAR);
	if (ft_tab_len(tmp) != 3 || ft_count_sep(s) != 2)
	{
		ft_free_tab(tmp);
		return (ft_inst_error("and (too few or too many args)", f, l));
	}
	if (tmp[0][0] == 'r')
		f = ft_reg_check(tmp[0], f, l, "and (1st param)");
	else if (ft_isind(tmp[0][0]))
		f = ft_ind_check(tmp[0], f, l, "and (1st param)");
	else if (tmp[0][0] == DIRECT_CHAR)
		f = ft_dir_check(tmp[0], f, l, "and (1st param)");
	else
		f = ft_inst_error("and (1st param)", f, l);
	return (ft_and2(tmp, f, l));
}

t_champ		*ft_or2(char **tmp, t_champ *f, int l)
{
	if (tmp[1][0] == 'r')
		f = ft_reg_check(tmp[1], f, l, "or (2nd param)");
	else if (ft_isind(tmp[1][0]))
		f = ft_ind_check(tmp[1], f, l, "or (2nd param)");
	else if (tmp[1][0] == DIRECT_CHAR)
		f = ft_dir_check(tmp[1], f, l, "or (2nd param)");
	else
		f = ft_inst_error("or (2nd param)", f, l);
	f = ft_reg_check(tmp[2], f, l, "or (3rd param)");
	ft_free_tab(tmp);
	return (f);
}

t_champ		*ft_or(char *s, t_champ *f, int l)
{
	char	**tmp;
	int		i;

	i = 0;
	f->size += 2;
	tmp = ft_splittrim(s, SEPARATOR_CHAR);
	if (ft_tab_len(tmp) != 3 || ft_count_sep(s) != 2)
	{
		ft_free_tab(tmp);
		return (ft_inst_error("or (too few or too many args)", f, l));
	}
	if (tmp[0][0] == 'r')
		f = ft_reg_check(tmp[0], f, l, "or (1st param)");
	else if (ft_isind(tmp[0][0]))
		f = ft_ind_check(tmp[0], f, l, "or (1st param)");
	else if (tmp[0][0] == DIRECT_CHAR)
		f = ft_dir_check(tmp[0], f, l, "or (1st param)");
	else
		f = ft_inst_error("or (1st param)", f, l);
	return (ft_or2(tmp, f, l));
}
