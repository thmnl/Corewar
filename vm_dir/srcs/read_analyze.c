/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_analyze.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:38:41 by brocher           #+#    #+#             */
/*   Updated: 2018/04/19 14:02:38 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_struct.h"
#include "vm_proto.h"
#include "errors.h"
#include <fcntl.h>
#include <errno.h>

char			*get_name(int fd, char *name)
{
	unsigned char	tmp[4];
	char			buf[PROG_NAME_LENGTH + 1];
	char			*str;
	int				i;
	char			magic[5];

	magic[0] = (char)(COREWAR_EXEC_MAGIC >> 24) & (char)0x000000FF;
	magic[1] = (char)(COREWAR_EXEC_MAGIC >> 16) & (char)0x000000FF;
	magic[2] = (char)(COREWAR_EXEC_MAGIC >> 8) & (char)0x000000FF;
	magic[3] = (char)COREWAR_EXEC_MAGIC & (char)0x000000FF;
	magic[4] = '\0';
	i = 0;
	while (i < PROG_NAME_LENGTH + 1)
		buf[i++] = 0;
	if (read(fd, tmp, 4) < 4)
		error("champion with no instruction or unreadable file", name);
	if (read(fd, buf, PROG_NAME_LENGTH) <= 0)
		error("champion with no instruction or unreadable file", name);
	str = ft_strnew(ft_strlen(buf));
	if (str == NULL)
		error("out of memory", NULL);
	if (ft_memcmp(tmp, magic, 4))
		error("wrong magic, you're not a wizard", name);
	ft_strcpy(str, buf);
	return (str);
}

char			*get_comment(int fd, char *name, int *size)
{
	unsigned char	tmp[8];
	char			buf[COMMENT_LENGTH + 1];
	char			*str;
	int				i;

	i = 0;
	while (i < COMMENT_LENGTH + 1)
		buf[i++] = 0;
	if (read(fd, tmp, 8) < 8)
		error("charmpion with no instruction or unreadable file", name);
	if (read(fd, buf, COMMENT_LENGTH) <= 0)
		error("champion with no instruction or unreadable file", name);
	ft_memcpy(size, tmp + 4, 4);
	ft_memrev(size, 4);
	str = ft_strnew(ft_strlen(buf));
	if (str == NULL)
		error("out of memory", NULL);
	ft_strcpy(str, buf);
	return (str);
}

unsigned char	*get_inst(t_champ *champ, int ord, int fd, char *name)
{
	unsigned char	tmp[4];
	unsigned char	buf[CHAMP_MAX_SIZE + 1];
	unsigned char	*str;
	int				i;
	int				rt;

	i = 0;
	while (i < CHAMP_MAX_SIZE + 1)
		buf[i++] = 0;
	if (read(fd, tmp, 4) < 4)
		error("champion with no instruction or unreadable file", name);
	if ((rt = read(fd, buf, CHAMP_MAX_SIZE + 1)) < 0)
		error("unreadable file", name);
	if (rt > CHAMP_MAX_SIZE)
		error("the size of the champion is too big", name);
	champ[ord].size = rt;
	str = ft_meminit(CHAMP_MAX_SIZE, 0);
	ft_memcpy(str, buf, CHAMP_MAX_SIZE);
	return (str);
}

void			get_champion(t_champ *champ, char *str, int ord)
{
	int		fd;
	int		champ_size;

	champ_size = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		error(strerror(errno), str);
	champ[ord].name = get_name(fd, str);
	champ[ord].comment = get_comment(fd, str, &champ_size);
	champ[ord].inst = get_inst(champ, ord, fd, str);
	champ[ord].live[0] = 1;
	champ[ord].live[1] = 1;
	if (champ[ord].size != champ_size)
		error("header size differs from real size", str);
	if (REG_NUMBER * REG_SIZE <= 0)
		error("no memory allocated for champion's registeries", NULL);
}

void			read_analyze(t_champ *champ, t_options *opt)
{
	int			ord;
	t_list		*nav;
	t_player	*player;

	ord = 0;
	nav = opt->p_list;
	while (nav)
	{
		player = (t_player*)nav->content;
		get_champion(champ, player->path, ord);
		nav = nav->next;
		ord++;
	}
}
