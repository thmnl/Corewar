/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:18:44 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/15 15:47:30 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int			ft_label2(char *lab, int l, char *tmp)
{
	int i;
	int j;
	int check;
	int c;

	i = 0;
	c = 0;
	(void)l;
	while (lab[i])
	{
		check = 0;
		j = 0;
		while (tmp[j])
		{
			if (tmp[j] == lab[i])
				check = 1;
			j++;
		}
		if (!check)
			c = 1;
		i++;
	}
	return (c);
}

static t_champ		*ft_label(t_champ *f, char *lab, int l)
{
	char	*tmp;

	tmp = ft_strdup(LABEL_CHARS);
	if (!ft_label2(lab, l, tmp))
	{
		if (!f->labels)
			f->labels = ft_strdup(lab);
		else
		{
			f->labels = ft_strjoin_free(f->labels, " ", 1);
			f->labels = ft_strjoin_free(f->labels, lab, 1);
		}
	}
	free(tmp);
	return (f);
}

static char			*ft_find_lab(char *s, int i)
{
	char	*r;

	r = NULL;
	while (s[i] && s[i] != LABEL_CHAR)
		i++;
	if (s[i])
	{
		if (i > 0 && s[i - 1] == DIRECT_CHAR)
		{
			if (s[i + 1] == ' ' || !s[i + 1])
			{
				s[i] = '\0';
				r = ft_strdup(s);
				s[i] = LABEL_CHAR;
			}
		}
		else
		{
			s[i] = '\0';
			r = ft_strdup(s);
			s[i] = LABEL_CHAR;
		}
	}
	return (r);
}

static t_champ		*ft_find_label(t_champ *f)
{
	int		i;
	int		l;
	char	*s;

	i = 0;
	while (f->ist[i])
	{
		s = ft_find_lab(f->ist[i], 0);
		l = ft_find_line(f->ist[i], f->path);
		if (s)
			f = ft_label(f, s, l);
		ft_strdel(&s);
		i++;
	}
	return (f);
}

t_champ				*ft_check_error4(t_champ *f)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (f->tchamp[j])
		j++;
	while (f->tchamp[i] && f->tchamp[i][0] == '.' && i < 2)
		i++;
	if (!(f->ist = (char **)malloc(sizeof(char *) * (j - i + 1))))
		ft_exit("Malloc error");
	j = 0;
	while (f->tchamp[i])
	{
		f->ist[j] = ft_strdup(f->tchamp[i]);
		j++;
		i++;
	}
	f->ist[j] = 0;
	if (f->ist[0] == 0)
		exit(ft_printf("\x1b[138;1;31m%s: No instruction\x1b[0m\n", f->path));
	f = ft_find_label(f);
	return (ft_check_error5(f));
}
