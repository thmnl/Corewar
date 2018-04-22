/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 15:31:13 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/16 14:24:01 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_champ		*ft_ind_check(char *s, t_champ *f, int l, char *inst)
{
	int i;

	i = 0;
	f = ft_ind_size(f);
	if (s[i] == LABEL_CHAR)
	{
		if (!ft_check_label(s + i + 1, f, 0))
			return (ft_bad_label(inst, f, l));
		return (f);
	}
	if (s[i] != '+' && s[i] != '-' && !ft_isdigit(s[i]))
		return (ft_inst_error(inst, f, l));
	i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			ft_lexic_error(s, f, l, i);
		i++;
	}
	return (f);
}

t_champ		*ft_reg_check(char *s, t_champ *f, int l, char *inst)
{
	int i;
	int r;

	r = -1;
	i = 0;
	f = ft_reg_size(f);
	if (s[i] != 'r')
		return (ft_inst_error(inst, f, l));
	i++;
	r = ft_atoi(s + i);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (ft_inst_error(inst, f, l));
		i++;
	}
	if (r < 0 || r >= REG_NUMBER)
		return (ft_inst_error(inst, f, l));
	return (f);
}

t_champ		*ft_dir_check(char *s, t_champ *f, int l, char *inst)
{
	int i;

	i = 0;
	f = ft_dir_size(f, inst);
	if (s[i] != DIRECT_CHAR)
		return (ft_inst_error(inst, f, l));
	i++;
	if (s[i] == LABEL_CHAR)
	{
		if (!ft_check_label(s + i + 1, f, 0))
			return (ft_bad_label(inst, f, l));
		else
			return (f);
	}
	if (s[i] != '+' && s[i] != '-' && !ft_isdigit(s[i]))
		return (ft_inst_error(inst, f, l));
	i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			ft_lexic_error(s, f, l, i);
		i++;
	}
	return (f);
}
