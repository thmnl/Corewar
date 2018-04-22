/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 12:36:49 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/19 19:01:19 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_champ	*ft_remove_com2(t_champ *f, int i, int j)
{
	while (f->champ[i])
	{
		if (f->champ[i][0] && f->champ[i][0] != COMMENT_CHAR)
		{
			f->tchamp[j] = ft_strdup(f->champ[i]);
			if (f->tchamp[j][0] != '.')
				f->tchamp[j] = ft_swap_char(f->tchamp[j], '\t', ' ');
			j++;
		}
		i++;
	}
	f->tchamp[j] = 0;
	i = 0;
	while (f->champ[i])
	{
		free(f->champ[i]);
		i++;
	}
	free(f->champ);
	f->champ = NULL;
	return (ft_check_error3(f));
}

static t_champ	*ft_remove_com(t_champ *f, int i, int j)
{
	char	*tmp;

	while (f->champ[i])
	{
		if (f->champ[i][0] != '.')
			f->champ[i] = ft_swap_char(f->champ[i], COMMENT_CHAR, '\0');
		else
			f->champ[i] = ft_remove_com_from_cmd(f->champ[i], COMMENT_CHAR);
		tmp = ft_strtrim(f->champ[i]);
		ft_strdel(&f->champ[i]);
		f->champ[i] = ft_strdup(tmp);
		ft_strdel(&tmp);
		if (!f->champ[i][0] || f->champ[i][0] == COMMENT_CHAR)
			j++;
		i++;
	}
	if (!(f->tchamp = (char **)malloc(sizeof(char *) * (i - j + 1))))
		ft_exit("Malloc error");
	return (ft_remove_com2(f, 0, 0));
}

static t_champ	*ft_check_error2(char *path, t_champ *f)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	if ((fd = open(path, O_RDONLY)) == -1)
		ft_exit("File does not exist/is invalid");
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0])
		{
			f->champ[i] = ft_strdup(line);
			i++;
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	f->champ[i] = 0;
	close(fd);
	return (ft_remove_com(f, 0, 0));
}

t_champ			*ft_check_error(char *path, t_champ *f)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	if ((fd = open(path, O_RDONLY)) == -1)
		return (ft_error("File does not exist/is invalid", f));
	if (lseek(fd, 0, SEEK_END) == 0)
		return (ft_error("file too small (length=0)", f));
	close(fd);
	if ((fd = open(path, O_RDONLY)) == -1)
		return (ft_error("Open error", f));
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0])
			i++;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(fd);
	if (!(f->champ = (char **)malloc(sizeof(char *) * (i + 1))))
		ft_exit("Malloc error");
	return (ft_check_error2(path, f));
}
