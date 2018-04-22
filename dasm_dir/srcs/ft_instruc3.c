/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruc3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 20:25:13 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/17 20:48:46 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dasm.h"

void		ft_add(int fd, t_dc *f)
{
	char buf[1];

	read(fd, buf, 1);
	f->ist = ft_strjoin_free(f->ist, "\nadd ", 1);
	ft_reg(fd, f);
	f->ist = ft_strjoin_free(f->ist, ", ", 1);
	ft_reg(fd, f);
	f->ist = ft_strjoin_free(f->ist, ", ", 1);
	ft_reg(fd, f);
}

void		ft_sub(int fd, t_dc *f)
{
	char buf[1];

	read(fd, buf, 1);
	f->ist = ft_strjoin_free(f->ist, "\nsub ", 1);
	ft_reg(fd, f);
	f->ist = ft_strjoin_free(f->ist, ", ", 1);
	ft_reg(fd, f);
	f->ist = ft_strjoin_free(f->ist, ", ", 1);
	ft_reg(fd, f);
}

void		ft_and(int fd, t_dc *f)
{
	char op[1];

	read(fd, op, 1);
	f->ist = ft_strjoin_free(f->ist, "\nand ", 1);
	if ((op[0] & 0x80) && (op[0] & 0x40))
		ft_ind(fd, f);
	else if ((op[0] & 0x80) && !(op[0] & 0x40))
		ft_dir4(fd, f);
	else
		ft_reg(fd, f);
	f->ist = ft_strjoin_free(f->ist, ", ", 1);
	if ((op[0] & 0x20) && (op[0] & 0x10))
		ft_ind(fd, f);
	else if ((op[0] & 0x20) && !(op[0] & 0x10))
		ft_dir4(fd, f);
	else
		ft_reg(fd, f);
	f->ist = ft_strjoin_free(f->ist, ", ", 1);
	ft_reg(fd, f);
}

void		ft_or(int fd, t_dc *f)
{
	char op[1];

	read(fd, op, 1);
	f->ist = ft_strjoin_free(f->ist, "\nor ", 1);
	if ((op[0] & 0x80) && (op[0] & 0x40))
		ft_ind(fd, f);
	else if ((op[0] & 0x80) && !(op[0] & 0x40))
		ft_dir4(fd, f);
	else
		ft_reg(fd, f);
	f->ist = ft_strjoin_free(f->ist, ", ", 1);
	if ((op[0] & 0x20) && (op[0] & 0x10))
		ft_ind(fd, f);
	else if ((op[0] & 0x20) && !(op[0] & 0x10))
		ft_dir4(fd, f);
	else
		ft_reg(fd, f);
	f->ist = ft_strjoin_free(f->ist, ", ", 1);
	ft_reg(fd, f);
}

void		ft_xor(int fd, t_dc *f)
{
	char op[1];

	read(fd, op, 1);
	f->ist = ft_strjoin_free(f->ist, "\nxor ", 1);
	if ((op[0] & 0x80) && (op[0] & 0x40))
		ft_ind(fd, f);
	else if ((op[0] & 0x80) && !(op[0] & 0x40))
		ft_dir4(fd, f);
	else
		ft_reg(fd, f);
	f->ist = ft_strjoin_free(f->ist, ", ", 1);
	if ((op[0] & 0x20) && (op[0] & 0x10))
		ft_ind(fd, f);
	else if ((op[0] & 0x20) && !(op[0] & 0x10))
		ft_dir4(fd, f);
	else
		ft_reg(fd, f);
	f->ist = ft_strjoin_free(f->ist, ", ", 1);
	ft_reg(fd, f);
}
