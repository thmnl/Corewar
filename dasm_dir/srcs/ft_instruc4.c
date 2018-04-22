/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruc4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 20:32:59 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/17 22:01:04 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dasm.h"

void		ft_ldi(int fd, t_dc *f)
{
	char op[1];

	read(fd, op, 1);
	f->ist = ft_strjoin_free(f->ist, "\nldi ", 1);
	if ((op[0] & 0x80) && (op[0] & 0x40))
		ft_ind(fd, f);
	else if ((op[0] & 0x80) && !(op[0] & 0x40))
		ft_dir2(fd, f);
	else
		ft_reg(fd, f);
	f->ist = ft_strjoin_free(f->ist, ", ", 1);
	if ((op[0] & 0x20) && !(op[0] & 0x10))
		ft_dir2(fd, f);
	else
		ft_reg(fd, f);
	f->ist = ft_strjoin_free(f->ist, ", ", 1);
	ft_reg(fd, f);
}

void		ft_lld(int fd, t_dc *f)
{
	char op[1];

	read(fd, op, 1);
	f->ist = ft_strjoin_free(f->ist, "\nlld ", 1);
	if ((op[0] & 0x80) && (op[0] & 0x40))
		ft_ind(fd, f);
	else
		ft_dir4(fd, f);
	f->ist = ft_strjoin_free(f->ist, ", ", 1);
	ft_reg(fd, f);
}

void		ft_lldi(int fd, t_dc *f)
{
	char op[1];

	read(fd, op, 1);
	f->ist = ft_strjoin_free(f->ist, "\nlldi ", 1);
	if ((op[0] & 0x80) && (op[0] & 0x40))
		ft_ind(fd, f);
	else if ((op[0] & 0x80) && !(op[0] & 0x40))
		ft_dir2(fd, f);
	else
		ft_reg(fd, f);
	f->ist = ft_strjoin_free(f->ist, ", ", 1);
	if ((op[0] & 0x20) && !(op[0] & 0x10))
		ft_dir2(fd, f);
	else
		ft_reg(fd, f);
	f->ist = ft_strjoin_free(f->ist, ", ", 1);
	ft_reg(fd, f);
}

void		ft_lfork(int fd, t_dc *f)
{
	f->ist = ft_strjoin_free(f->ist, "\nlfork ", 1);
	ft_dir2(fd, f);
}

void		ft_aff(int fd, t_dc *f)
{
	char buf[1];

	read(fd, buf, 1);
	f->ist = ft_strjoin_free(f->ist, "\naff ", 1);
	ft_reg(fd, f);
}
