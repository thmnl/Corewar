/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 10:07:28 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/14 20:00:18 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				ft_check_label2(char *s, t_champ *f, int check)
{
	char	**tmp;
	int		i;
	char	*tmp2;

	i = 0;
	if (!f->labels)
		return (0);
	tmp2 = ft_strnew(ft_strlen(s));
	tmp = ft_strsplit(f->labels, ' ');
	while (s[i] && (s[i] != LABEL_CHAR))
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

static char		*ft_label(char *s, int i, t_champ *f)
{
	char	*r;

	r = NULL;
	if (!ft_check_label2(s, f, 0))
		return (r);
	while (s[i] && s[i] != ':')
		i++;
	if (s[i])
	{
		if (s[i - 1] == '%')
		{
			if (s[i + 1] == ' ' || !s[i + 1])
				r = NULL;
		}
		else
			r = ft_strchr(s, ':') + 1;
	}
	return (r);
}

t_champ			*ft_check_inst2(char *s, t_champ *f, int l, int i)
{
	char	**tmp;

	if (!(tmp = ft_strsplit(s, ' ')))
		ft_exit("Malloc error");
	if (!ft_strcmp(tmp[0], "xor"))
		ft_xor(s + i + 3, f, l);
	else if (!ft_strcmp(tmp[0], "zjmp"))
		ft_zjmp(s + i + 4, f, l);
	else if (!ft_strcmp(tmp[0], "ldi"))
		ft_ldi(s + i + 3, f, l);
	else if (!ft_strcmp(tmp[0], "sti"))
		ft_sti(s + i + 3, f, l);
	else if (!ft_strcmp(tmp[0], "fork"))
		ft_fork(s + i + 4, f, l);
	else if (!ft_strcmp(tmp[0], "lld"))
		ft_lld(s + i + 3, f, l);
	else if (!ft_strcmp(tmp[0], "lldi"))
		ft_lldi(s + i + 4, f, l);
	else if (!ft_strcmp(tmp[0], "lfork"))
		ft_lfork(s + i + 5, f, l);
	else if (!ft_strcmp(tmp[0], "aff"))
		ft_aff(s + i + 3, f, l);
	else
		ft_check_error6(s, f, l);
	return (ft_free_ret(f, tmp));
}

t_champ			*ft_check_inst(char *s, t_champ *f, int l, int i)
{
	char	**tmp;

	if (s[0] == ' ')
		i++;
	if (!(tmp = ft_strsplit(s, ' ')))
		ft_exit("Malloc error");
	if (!ft_strcmp(tmp[0], "live"))
		ft_live(s + i + 4, f, l);
	else if (!ft_strcmp(tmp[0], "ld"))
		ft_ld(s + i + 2, f, l);
	else if (!ft_strcmp(tmp[0], "st"))
		ft_st(s + i + 2, f, l);
	else if (!ft_strcmp(tmp[0], "add"))
		ft_add(s + i + 3, f, l);
	else if (!ft_strcmp(tmp[0], "sub"))
		ft_sub(s + i + 3, f, l);
	else if (!ft_strcmp(tmp[0], "and"))
		ft_and(s + i + 3, f, l);
	else if (!ft_strcmp(tmp[0], "or"))
		ft_or(s + i + 2, f, l);
	else
		ft_check_inst2(s, f, l, i);
	ft_free_tab(tmp);
	return (f);
}

t_champ			*ft_check_error5(t_champ *f)
{
	int		i;
	char	*s;
	int		l;

	i = 0;
	while (f->ist[i])
	{
		l = ft_find_line(f->ist[i], f->path);
		s = ft_label(f->ist[i], 0, f);
		if (s && s[0])
			f = ft_check_inst(s + 1, f, l, 0);
		else
			f = ft_check_inst(f->ist[i], f, l, 0);
		i++;
	}
	return (f);
}
