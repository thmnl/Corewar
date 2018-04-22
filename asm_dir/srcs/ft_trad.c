/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <gperilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:47:41 by gperilla          #+#    #+#             */
/*   Updated: 2018/04/19 11:57:28 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	ft_creat(t_champ *f)
{
	int		i;

	i = ft_strlen(f->path);
	while (i > 0 && f->path[i] != '.')
		--i;
	if (!(f->file = malloc(sizeof(char) * i + 5)))
		exit(0);
	ft_strncpy(f->file, f->path, i);
	ft_strcpy(f->file + i, ".cor");
	f->fd = open(f->file, O_WRONLY | O_CREAT | O_TRUNC, 0744);
}

void	ft_magic(t_champ *f)
{
	ft_putchar_fd((char)(COREWAR_EXEC_MAGIC >> 24), f->fd);
	ft_putchar_fd((char)(COREWAR_EXEC_MAGIC >> 16), f->fd);
	ft_putchar_fd((char)(COREWAR_EXEC_MAGIC >> 8), f->fd);
	ft_putchar_fd((char)(COREWAR_EXEC_MAGIC >> 0), f->fd);
}

void	ft_name(t_champ *f)
{
	int i;

	ft_putstr_fd(f->name, f->fd);
	i = ft_strlen(f->name);
	while (i++ < PROG_NAME_LENGTH + 4)
		ft_putchar_fd(0, f->fd);
}

void	ft_size_comment(t_champ *f)
{
	int i;

	i = (int)sizeof(((t_header *)0)->prog_size);
	while (--i >= 0)
		ft_putchar_fd(f->size >> i * 8, f->fd);
	ft_putstr_fd(f->comment, f->fd);
	i = ft_strlen(f->comment);
	while (i++ < COMMENT_LENGTH + 4)
		ft_putchar_fd(0, f->fd);
}

void	ft_trad(t_champ *f)
{
	f->oct = 0;
	ft_creat(f);
	ft_magic(f);
	ft_name(f);
	ft_size_comment(f);
	ft_recup_label(f);
	ft_ope(f);
	ft_printf("Writing output program to %s\n", f->file);
	free(f->file);
}
