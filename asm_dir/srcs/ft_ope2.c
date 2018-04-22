/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ope2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <gperilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 01:48:57 by gperilla          #+#    #+#             */
/*   Updated: 2018/04/20 11:47:03 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_oplive(t_champ *f, char *line)
{
	int i;
	int d;
	int cpt;

	cpt = 0;
	ft_putchar_fd(0x01, f->fd);
	++cpt;
	i = ft_get_next_symbol(line, 0, '%', 0);
	if (line[i] == ':')
		i = ft_get_label_value(f, line + i);
	else
		i = ft_atoi(line + i);
	d = 32;
	while ((d = d - 8) >= 0)
	{
		ft_putchar_fd(i >> d, f->fd);
		++cpt;
	}
	f->oct += cpt;
}

static void	ft_nrmopld(t_champ *f, char *line, int *i, int *d)
{
	ft_opocd(f, line);
	*i = ft_get_next_symbol(line, 0, ' ', 1);
	*d = 16;
	if (line[*i] == '%')
	{
		*d = 32;
		++*i;
	}
}

void		ft_opld(t_champ *f, char *line)
{
	int i;
	int val;
	int d;
	int cpt;

	cpt = 0;
	ft_putchar_fd(0x02, f->fd);
	cpt += 2;
	ft_nrmopld(f, line, &i, &d);
	if (line[i] == ':')
		val = ft_get_label_value(f, line + i);
	else
		val = ft_atoi(line + i);
	while ((d = d - 8) >= 0)
	{
		ft_putchar_fd(val >> d, f->fd);
		++cpt;
	}
	i = ft_get_next_symbol(line, i, ',', 1);
	val = ft_atoi(line + i + 1);
	ft_putchar_fd(val, f->fd);
	++cpt;
	f->oct += cpt;
}

static void	ft_nrmopst(t_champ *f, char *line, int *i, int *cpt)
{
	*cpt = 0;
	ft_putchar_fd(0x03, f->fd);
	++*cpt;
	ft_opocd(f, line);
	++*cpt;
	*i = ft_get_next_symbol(line, 0, ' ', 1);
	ft_putchar_fd(ft_atoi(line + *i + 1), f->fd);
	++*cpt;
}

void		ft_opst(t_champ *f, char *line)
{
	int i;
	int val;
	int d;
	int cpt;

	ft_nrmopst(f, line, &i, &cpt);
	i = ft_get_next_symbol(line, i, ',', 1);
	d = 16;
	val = ft_atoi(line + i);
	if (line[i] == 'r')
	{
		d = 8;
		++i;
		val = ft_atoi(line + i);
	}
	else if (line[i] == ':')
		val = ft_get_label_value(f, line + i);
	while ((d -= 8) >= 0)
	{
		ft_putchar_fd(val >> d, f->fd);
		++cpt;
	}
	f->oct += cpt;
}
