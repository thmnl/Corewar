/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:12:51 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/16 14:38:48 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_champ		*ft_bad_ligne(char *s, t_champ *f, int l)
{
	int i;
	int j;

	l++;
	j = 0;
	if (s)
		j = ft_strlen(s);
	ft_putstr("\x1b[138;1;31m");
	i = ft_printf("%s: Ligne %d is invalid. (%s)\n", f->path, l, s) - 1;
	j = i - j;
	while (j-- > 1)
		ft_putchar(' ');
	if (s)
		j = ft_strlen(s);
	ft_putstr("\x1b[183;1;92m");
	while (j-- > 0)
		ft_putchar('~');
	ft_putchar('\n');
	ft_putstr("\x1B[0m");
	f->error = 1;
	return (f);
}

int			ft_check_label3(char *s, t_champ *f, int check)
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

t_champ		*ft_check_error6(char *s, t_champ *f, int l)
{
	int	i;

	i = 0;
	if (s[ft_strlen(s) - 1] != LABEL_CHAR)
		return (ft_bad_ligne(s, f, l));
	else if (!ft_check_label3(s, f, 0))
		return (ft_bad_label(s, f, l));
	return (f);
}

t_champ		*ft_free_ret(t_champ *f, char **tmp)
{
	ft_free_tab(tmp);
	return (f);
}
