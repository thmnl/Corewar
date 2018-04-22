/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decrypt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:04:04 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/19 19:49:36 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dasm.h"

static void		ft_dc_comment(int fd, t_dc *f)
{
	char *buf;

	buf = ft_strnew(COMMENT_LENGTH);
	read(fd, buf, COMMENT_LENGTH + 1);
	f->comment = ft_strdup(buf);
	read(fd, buf, 3);
	free(buf);
}

static void		ft_dc_name(int fd, t_dc *f)
{
	char *buf;

	buf = ft_strnew(PROG_NAME_LENGTH);
	read(fd, buf, PROG_NAME_LENGTH + 1);
	f->name = ft_strdup(buf);
	read(fd, buf, 3);
	free(buf);
}

static void		ft_dc_size(int fd)
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
	if (num > CHAMP_MAX_SIZE)
	{
		ft_putstr("\x1b[138;1;31m");
		ft_putendl("Champ too big my dude, but I'll try, mah boy don't worry");
		ft_putstr("\x1B[0m");
	}
}

static void		ft_dc_magic(int fd)
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
	if (num != COREWAR_EXEC_MAGIC)
		ft_exit("Wrong file type my dude, relax and try another one");
}

void			ft_decrypt(char *path, t_dc *f)
{
	int fd;

	if ((fd = open(path, O_RDONLY)) == -1)
		ft_exit("File does not exist/is invalid my dude");
	if (lseek(fd, 0, SEEK_END) == 0)
		ft_exit("file too small (length=0) my dude");
	close(fd);
	if ((fd = open(path, O_RDONLY)) == -1)
		ft_exit("File does not exist/is invalid my dude");
	ft_dc_magic(fd);
	ft_dc_name(fd, f);
	ft_dc_size(fd);
	ft_dc_comment(fd, f);
	ft_dc_inst(fd, f);
	close(fd);
}
