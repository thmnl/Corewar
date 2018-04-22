/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ope4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <gperilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 02:00:06 by gperilla          #+#    #+#             */
/*   Updated: 2018/04/18 02:02:10 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_opzjmp(t_champ *f, char *line)
{
	int i;
	int cpt;
	int val;

	cpt = 0;
	ft_putchar_fd(0x09, f->fd);
	++cpt;
	i = ft_get_next_symbol(line, 0, '%', 1);
	val = ft_atoi(line + i);
	if (line[i] == ':')
		val = ft_get_label_value(f, line + i);
	ft_putchar_fd(val >> 8, f->fd);
	++cpt;
	ft_putchar_fd(val, f->fd);
	++cpt;
	f->oct += cpt;
}

void	ft_opldi(t_champ *f, char *line)
{
	int i;
	int val;
	int d;
	int cpt;

	cpt = 0;
	ft_putchar_fd(0x0a, f->fd);
	++cpt;
	ft_opocd(f, line);
	++cpt;
	i = ft_get_next_symbol(line, 0, ' ', 1);
	while (line[i])
	{
		ft_get_d_val2(&d, &val, line + i, f);
		while ((d -= 8) >= 0)
		{
			ft_putchar_fd(val >> d, f->fd);
			++cpt;
		}
		i = ft_get_next_symbol(line, i, ',', 1);
	}
	f->oct += cpt;
}

void	ft_opsti(t_champ *f, char *line)
{
	int i;
	int val;
	int d;
	int cpt;

	cpt = 0;
	ft_putchar_fd(0x0b, f->fd);
	++cpt;
	ft_opocd(f, line);
	++cpt;
	i = ft_get_next_symbol(line, 0, ' ', 1);
	while (line[i])
	{
		ft_get_d_val2(&d, &val, line + i, f);
		while ((d -= 8) >= 0)
		{
			ft_putchar_fd(val >> d, f->fd);
			++cpt;
		}
		i = ft_get_next_symbol(line, i, ',', 1);
	}
	f->oct += cpt;
}

void	ft_opfork(t_champ *f, char *line)
{
	int i;
	int val;
	int cpt;

	cpt = 0;
	ft_putchar_fd(0x0c, f->fd);
	++cpt;
	i = ft_get_next_symbol(line, 0, '%', 1);
	val = ft_atoi(line + i);
	if (line[i] == ':')
		val = ft_get_label_value(f, line + i);
	ft_putchar_fd(val >> 8, f->fd);
	++cpt;
	ft_putchar_fd(val, f->fd);
	++cpt;
	f->oct += cpt;
}

void	ft_oplld(t_champ *f, char *line)
{
	int i;
	int val;
	int d;
	int cpt;

	cpt = 0;
	ft_putchar_fd(0x0d, f->fd);
	++cpt;
	ft_opocd(f, line);
	++cpt;
	i = ft_get_next_symbol(line, 0, ' ', 1);
	ft_get_d_val(&d, &val, line + i, f);
	while ((d -= 8) >= 0)
	{
		ft_putchar_fd(val >> d, f->fd);
		++cpt;
	}
	i = ft_get_next_symbol(line, 0, ',', 1);
	ft_putchar_fd(ft_atoi(line + i + 1), f->fd);
	++cpt;
	f->oct += cpt;
}
