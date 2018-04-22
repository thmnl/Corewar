/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decrypt2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:30:23 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/19 20:23:39 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dasm.h"

static void		ft_redir2(char c, int fd, t_dc *f)
{
	if (c == 8)
		ft_xor(fd, f);
	else if (c == 10)
		ft_ldi(fd, f);
	else if (c == 13)
		ft_lld(fd, f);
	else if (c == 14)
		ft_lldi(fd, f);
	else if (c == 15)
		ft_lfork(fd, f);
	else if (c == 16)
		ft_aff(fd, f);
	else
		ft_exit("Something wrong my dude");
}

static void		ft_redir(char c, int fd, t_dc *f)
{
	if (c == 1)
		ft_live(fd, f);
	else if (c == 11)
		ft_sti(fd, f);
	else if (c == 12)
		ft_fork(fd, f);
	else if (c == 9)
		ft_zjmp(fd, f);
	else if (c == 2)
		ft_ld(fd, f);
	else if (c == 3)
		ft_st(fd, f);
	else if (c == 4)
		ft_add(fd, f);
	else if (c == 5)
		ft_sub(fd, f);
	else if (c == 6)
		ft_and(fd, f);
	else if (c == 7)
		ft_or(fd, f);
	else
		ft_redir2(c, fd, f);
}

void			ft_dc_inst(int fd, t_dc *f)
{
	char	buf[1];

	while (read(fd, buf, 1) > 0)
	{
		ft_redir(buf[0], fd, f);
	}
}
