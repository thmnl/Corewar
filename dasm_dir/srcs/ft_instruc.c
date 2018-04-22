/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:37:55 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/17 20:10:38 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dasm.h"

void		ft_live(int fd, t_dc *f)
{
	f->ist = ft_strjoin_free(f->ist, "\nlive ", 1);
	ft_dir4(fd, f);
}

void		ft_dir4(int fd, t_dc *f)
{
	char	buf[4];
	int		num;
	char	tmp;

	read(fd, buf, 4);
	tmp = buf[0];
	buf[0] = buf[3];
	buf[3] = tmp;
	tmp = buf[1];
	buf[1] = buf[2];
	buf[2] = tmp;
	num = *(int *)buf;
	f->ist = ft_strjoin_free(f->ist, "%", 1);
	f->ist = ft_strjoin_free(f->ist, ft_itoa(num), 3);
}

void		ft_dir2(int fd, t_dc *f)
{
	char	buf[4];
	int		num;
	char	tmp;

	buf[3] = '\0';
	buf[2] = '\0';
	buf[1] = '\0';
	buf[0] = '\0';
	read(fd, buf + 2, 2);
	tmp = buf[0];
	buf[0] = buf[3];
	buf[3] = tmp;
	tmp = buf[1];
	buf[1] = buf[2];
	buf[2] = tmp;
	num = *(int *)buf;
	f->ist = ft_strjoin_free(f->ist, "%", 1);
	f->ist = ft_strjoin_free(f->ist, ft_itoa(num), 3);
}

void		ft_reg(int fd, t_dc *f)
{
	char	buf[2];

	buf[1] = '\0';
	read(fd, buf, 1);
	f->ist = ft_strjoin_free(f->ist, "r", 1);
	f->ist = ft_strjoin_free(f->ist, ft_itoa(buf[0]), 3);
}

void		ft_ind(int fd, t_dc *f)
{
	char	buf[4];
	int		num;
	char	tmp;

	buf[3] = '\0';
	buf[2] = '\0';
	buf[1] = '\0';
	buf[0] = '\0';
	read(fd, buf + 2, 2);
	tmp = buf[0];
	buf[0] = buf[3];
	buf[3] = tmp;
	tmp = buf[1];
	buf[1] = buf[2];
	buf[2] = tmp;
	num = *(int *)buf;
	f->ist = ft_strjoin_free(f->ist, ft_itoa(num), 3);
}
