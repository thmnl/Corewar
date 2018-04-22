/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 12:30:52 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/16 14:35:38 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_champ		*ft_inst_error(char *s, t_champ *f, int l)
{
	l++;
	ft_putstr("\x1b[138;1;31m");
	ft_printf("%s: Invalid parameter for instruction %s ligne %d\n", f->path,
																		s, l);
	ft_putstr("\x1B[0m");
	f->error = 1;
	return (f);
}

t_champ		*ft_lexic_error(char *s, t_champ *f, int l, int j)
{
	int i;

	l++;
	ft_putstr("\x1b[138;1;31m");
	i = ft_printf("%s: Lexical error ligne %d (%s)\n", f->path, l, s);
	i -= ft_strlen(s) + 2;
	ft_putstr("\x1b[183;1;92m");
	while (i--)
		ft_putchar(' ');
	while (i + 2 <= (int)ft_strlen(s))
	{
		if (i == j - 1)
			ft_putchar('^');
		else
			ft_putchar('~');
		i++;
	}
	ft_putchar('\n');
	f->error = 1;
	ft_putstr("\x1B[0m");
	return (f);
}

t_champ		*ft_error(char *s, t_champ *f)
{
	ft_putstr("\x1b[138;1;31m");
	ft_printf("%s: %s\n", f->path, s);
	ft_putstr("\x1B[0m");
	f->error = 1;
	return (f);
}

t_champ		*ft_token_error(char *s, t_champ *f, int l)
{
	l++;
	ft_putstr("\x1b[138;1;31m");
	ft_printf("%s: Syntax error ligne %d (%s, token error)\n", f->path, l, s);
	ft_putstr("\x1B[0m");
	f->error = 1;
	return (f);
}

void		ft_exit(char *s)
{
	ft_putstr("\x1b[138;1;31m");
	ft_printf("%s\n", s);
	ft_putstr("\x1B[0m");
	exit(-1);
}
