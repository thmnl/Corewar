/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ope5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <gperilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 02:02:56 by gperilla          #+#    #+#             */
/*   Updated: 2018/04/19 11:14:59 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_oplldi(t_champ *f, char *line)
{
	int i;
	int val;
	int d;
	int cpt;

	cpt = 0;
	ft_putchar_fd(0x0e, f->fd);
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

void	ft_oplfork(t_champ *f, char *line)
{
	int i;
	int val;
	int cpt;

	cpt = 0;
	ft_putchar_fd(0x0f, f->fd);
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

void	ft_opaff(t_champ *f, char *line)
{
	int i;

	ft_putchar_fd(0x10, f->fd);
	++f->oct;
	ft_opocd(f, line);
	++f->oct;
	i = ft_get_next_symbol(line, 0, 'r', 1);
	ft_putchar_fd(ft_atoi(line + i), f->fd);
	++f->oct;
}
