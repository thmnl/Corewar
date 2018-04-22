/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruc2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:11:41 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/17 20:49:54 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dasm.h"

void		ft_sti(int fd, t_dc *f)
{
	char	op[1];

	f->ist = ft_strjoin_free(f->ist, "\nsti ", 1);
	read(fd, op, 1);
	ft_reg(fd, f);
	f->ist = ft_strjoin_free(f->ist, ", ", 1);
	if ((op[0] & 0x20) && (op[0] & 0x10))
		ft_ind(fd, f);
	else if ((op[0] & 0x20) && !(op[0] & 0x10))
		ft_dir2(fd, f);
	else
		ft_reg(fd, f);
	f->ist = ft_strjoin_free(f->ist, ", ", 1);
	if (!(op[0] & 0x08))
		ft_reg(fd, f);
	else
		ft_dir2(fd, f);
}

void		ft_fork(int fd, t_dc *f)
{
	f->ist = ft_strjoin_free(f->ist, "\nfork ", 1);
	ft_dir2(fd, f);
}

void		ft_zjmp(int fd, t_dc *f)
{
	f->ist = ft_strjoin_free(f->ist, "\nzjmp ", 1);
	ft_dir2(fd, f);
}

void		ft_st(int fd, t_dc *f)
{
	char	op[1];

	read(fd, op, 1);
	f->ist = ft_strjoin_free(f->ist, "\nst ", 1);
	ft_reg(fd, f);
	f->ist = ft_strjoin_free(f->ist, ", ", 1);
	if ((op[0] & 0x20) && (op[0] & 0x10))
		ft_ind(fd, f);
	else
		ft_reg(fd, f);
}

void		ft_ld(int fd, t_dc *f)
{
	char	op[1];

	read(fd, op, 1);
	f->ist = ft_strjoin_free(f->ist, "\nld ", 1);
	if ((op[0] & 0x80) && (op[0] & 0x40))
		ft_ind(fd, f);
	else
		ft_dir4(fd, f);
	f->ist = ft_strjoin_free(f->ist, ", ", 1);
	ft_reg(fd, f);
}
