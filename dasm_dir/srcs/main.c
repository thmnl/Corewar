/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:28:46 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/20 13:48:38 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dasm.h"

static void	ft_create_file2(int fd, t_dc *f)
{
	write(fd, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING));
	write(fd, " \"", 2);
	write(fd, f->name, ft_strlen(f->name));
	write(fd, "\"\n", 2);
	write(fd, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING));
	write(fd, " \"", 2);
	write(fd, f->comment, ft_strlen(f->comment));
	write(fd, "\"\n", 2);
	write(fd, f->ist, ft_strlen(f->ist));
	write(fd, "\n", 1);
	close(fd);
}

static void	ft_create_file(char *path, t_dc *f)
{
	int		fd;
	char	*file;
	int		i;

	i = ft_strlen(path);
	file = NULL;
	while (i)
	{
		if (path[i] == '.')
		{
			path[i] = '\0';
			file = ft_strdup(path);
			break ;
		}
		i--;
	}
	if (file)
		file = ft_strjoin_free(file, ".s", 1);
	else
		file = ft_strdup(".s");
	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_printf("Writing output file to %s\n", file);
	ft_create_file2(fd, f);
	free(file);
}

static void	ft_init(t_dc *f)
{
	f->name = NULL;
	f->comment = NULL;
	f->ist = ft_strdup("");
}

int			main(int ac, char **av)
{
	t_dc *f;

	if (ac < 2)
		return (ft_printf("Run dasm with arg\n"));
	if (!(f = (t_dc*)malloc(sizeof(t_dc))))
		ft_exit("Malloc error");
	ft_bzero(f, sizeof(t_dc));
	ft_init(f);
	ft_decrypt(av[1], f);
	ft_create_file(av[1], f);
	ft_strdel(&f->name);
	ft_strdel(&f->comment);
	free(f->ist);
	free(f);
	return (0);
}
