/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ope1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <gperilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 20:15:31 by gperilla          #+#    #+#             */
/*   Updated: 2018/04/20 12:45:04 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_get_next_symbol(char *str, int pos, char sbl, int skip_space)
{
	++pos;
	while (str[pos] && str[pos++] != sbl)
		continue;
	if (skip_space && str[pos] == ' ')
		++pos;
	return (pos);
}

void		ft_opocd(t_champ *f, char *line)
{
	int i;
	int d;
	int val;

	val = 0;
	d = 8;
	i = ft_get_next_symbol(line, -1, ' ', 0);
	while (line[i])
	{
		if (line[i] == 'r')
			val += (REG_CODE << (d = d - 2));
		else if (line[i] == '%')
			val += (DIR_CODE << (d = d - 2));
		else
			val += (IND_CODE << (d = d - 2));
		i = ft_get_next_symbol(line, i, ',', 1);
	}
	ft_putchar_fd(val, f->fd);
}

static void	init_optab(t_champ *f)
{
	f->optab[0] = (t_optab){"live", ft_oplive};
	f->optab[1] = (t_optab){"ld", ft_opld};
	f->optab[2] = (t_optab){"st", ft_opst};
	f->optab[3] = (t_optab){"add", ft_opadd};
	f->optab[4] = (t_optab){"sub", ft_opsub};
	f->optab[5] = (t_optab){"and", ft_opand};
	f->optab[6] = (t_optab){"or", ft_opor};
	f->optab[7] = (t_optab){"xor", ft_opxor};
	f->optab[8] = (t_optab){"zjmp", ft_opzjmp};
	f->optab[9] = (t_optab){"ldi", ft_opldi};
	f->optab[10] = (t_optab){"sti", ft_opsti};
	f->optab[11] = (t_optab){"fork", ft_opfork};
	f->optab[12] = (t_optab){"lld", ft_oplld};
	f->optab[13] = (t_optab){"lldi", ft_oplldi};
	f->optab[14] = (t_optab){"lfork", ft_oplfork};
	f->optab[15] = (t_optab){"aff", ft_opaff};
	f->optab[16] = (t_optab){NULL, NULL};
}

static void	ft_nrmope(t_champ *f, int i, int *k)
{
	*k = 0;
	while (f->ist[i][*k] != ' ' && f->ist[i][*k] != ':')
		++*k;
	if (f->ist[i][*k] == ' ')
		*k = 0;
	else
		while (f->ist[i][++*k] == ' ')
			continue;
}

void		ft_ope(t_champ *f)
{
	int		i;
	int		j;
	int		k;
	char	*op;

	init_optab(f);
	i = -1;
	while (f->ist[++i])
	{
		f->ist[i] = ft_remove_double_sp(f->ist[i]);
		ft_nrmope(f, i, &k);
		j = -1;
		while (f->ist[i][++j + k] && f->ist[i][j + k] != ' ')
			continue;
		op = ft_strsub(f->ist[i] + k, 0, j);
		j = -1;
		while (f->optab[++j].ope != NULL)
			if (ft_strequ(f->optab[j].ope, op))
				(f->optab[j].fct)(f, f->ist[i] + k);
		free(op);
	}
	ft_free_label(f);
}
