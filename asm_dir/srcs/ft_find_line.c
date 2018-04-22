/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 08:32:12 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/14 18:58:13 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	ft_line2(char *line, char *tmp, char *s)
{
	line = ft_swap_char(line, COMMENT_CHAR, '\0');
	tmp = ft_strtrim(line);
	if (tmp[0] != '.')
		tmp = ft_swap_char(tmp, '\t', ' ');
	ft_strdel(&line);
	if (!ft_strcmp(s, tmp))
	{
		ft_strdel(&tmp);
		return (1);
	}
	ft_strdel(&tmp);
	return (0);
}

int			ft_find_line(char *s, char *path)
{
	char	*line;
	int		fd;
	int		i;
	char	*tmp;

	line = NULL;
	tmp = NULL;
	i = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_line2(line, tmp, s))
			return (i);
		i++;
	}
	ft_strdel(&line);
	return (0);
}
