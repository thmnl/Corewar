/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ope3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <gperilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 01:54:06 by gperilla          #+#    #+#             */
/*   Updated: 2018/04/18 01:57:12 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_opadd(t_champ *f, char *line)
{
	int i;

	ft_putchar_fd(0x04, f->fd);
	++f->oct;
	ft_opocd(f, line);
	++f->oct;
	i = ft_get_next_symbol(line, 0, ' ', 1);
	ft_putchar_fd(ft_atoi(line + i + 1), f->fd);
	++f->oct;
	i = ft_get_next_symbol(line, i, ',', 1);
	ft_putchar_fd(ft_atoi(line + i + 1), f->fd);
	++f->oct;
	i = ft_get_next_symbol(line, i, ',', 1);
	ft_putchar_fd(ft_atoi(line + i + 1), f->fd);
	++f->oct;
}

void	ft_opsub(t_champ *f, char *line)
{
	int i;

	ft_putchar_fd(0x05, f->fd);
	++f->oct;
	ft_opocd(f, line);
	++f->oct;
	i = ft_get_next_symbol(line, 0, ' ', 1);
	ft_putchar_fd(ft_atoi(line + i + 1), f->fd);
	++f->oct;
	i = ft_get_next_symbol(line, i, ',', 1);
	ft_putchar_fd(ft_atoi(line + i + 1), f->fd);
	++f->oct;
	i = ft_get_next_symbol(line, i, ',', 1);
	ft_putchar_fd(ft_atoi(line + i + 1), f->fd);
	++f->oct;
}

void	ft_opand(t_champ *f, char *line)
{
	int i;
	int val;
	int d;
	int cpt;

	cpt = 0;
	ft_putchar_fd(0x06, f->fd);
	++cpt;
	ft_opocd(f, line);
	++cpt;
	i = ft_get_next_symbol(line, 0, ' ', 1);
	while (line[i])
	{
		ft_get_d_val(&d, &val, line + i, f);
		while ((d -= 8) >= 0)
		{
			ft_putchar_fd(val >> d, f->fd);
			++cpt;
		}
		i = ft_get_next_symbol(line, i, ',', 1);
	}
	f->oct += cpt;
}

void	ft_opor(t_champ *f, char *line)
{
	int i;
	int val;
	int d;
	int cpt;

	cpt = 0;
	ft_putchar_fd(0x07, f->fd);
	++cpt;
	ft_opocd(f, line);
	++cpt;
	i = ft_get_next_symbol(line, 0, ' ', 1);
	while (line[i])
	{
		ft_get_d_val(&d, &val, line + i, f);
		while ((d -= 8) >= 0)
		{
			ft_putchar_fd(val >> d, f->fd);
			++cpt;
		}
		i = ft_get_next_symbol(line, i, ',', 1);
	}
	f->oct += cpt;
}

void	ft_opxor(t_champ *f, char *line)
{
	int i;
	int val;
	int d;
	int cpt;

	cpt = 0;
	ft_putchar_fd(0x08, f->fd);
	++cpt;
	ft_opocd(f, line);
	++cpt;
	i = ft_get_next_symbol(line, 0, ' ', 1);
	while (line[i])
	{
		ft_get_d_val(&d, &val, line + i, f);
		while ((d -= 8) >= 0)
		{
			ft_putchar_fd(val >> d, f->fd);
			++cpt;
		}
		i = ft_get_next_symbol(line, i, ',', 1);
	}
	f->oct += cpt;
}
