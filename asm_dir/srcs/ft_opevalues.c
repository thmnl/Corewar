/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opevalues.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <gperilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 02:05:19 by gperilla          #+#    #+#             */
/*   Updated: 2018/04/20 11:50:58 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*ft_remove_double_sp(char *str)
{
	char	*s;
	int		i;
	int		j;
	char	c;

	if (!(s = malloc(sizeof(char) * (ft_strlen(str) + 1))))
		exit(1);
	ft_bzero(s, ft_strlen(str) + 1);
	i = -1;
	j = 0;
	c = 0;
	while (str[++i])
	{
		if (c == ' ' && str[i] == ' ')
			continue;
		s[j++] = str[i];
		c = str[i];
	}
	free(str);
	return (s);
}

static char	*ft_get_label_name(char *line)
{
	int i;

	i = 0;
	while (line[++i] && line[i] != ' ' && line[i] != ',')
		continue;
	if (line[i])
		--i;
	return (ft_strsub(line, 1, i));
}

int			ft_get_label_value(t_champ *f, char *line)
{
	char	*name;
	int		i;

	name = ft_get_label_name(line);
	i = -1;
	while (f->label[++i])
	{
		if (ft_strequ(name, f->label[i]->name))
		{
			free(name);
			return (f->label[i]->address - f->oct);
		}
	}
	free(name);
	return (0);
}

void		ft_get_d_val(int *d, int *val, char *line, t_champ *f)
{
	*d = 8;
	if (line[0] == 'r')
		*val = ft_atoi(line + 1);
	else if (line[0] == '%')
	{
		*d = 32;
		*val = ft_atoi(line + 1);
		if (line[1] == ':')
			*val = ft_get_label_value(f, line + 1);
	}
	else
	{
		*d = 16;
		*val = ft_atoi(line);
		if (line[0] == ':')
			*val = ft_get_label_value(f, line);
	}
}

void		ft_get_d_val2(int *d, int *val, char *line, t_champ *f)
{
	*d = 8;
	if (line[0] == 'r')
		*val = ft_atoi(line + 1);
	else
	{
		*d = 16;
		if (line[0] == '%' && line[1] != ':')
			*val = ft_atoi(line + 1);
		else if (line[0] == ':')
			*val = ft_get_label_value(f, line);
		else if (line[0] == '%' && line[1] == ':')
			*val = ft_get_label_value(f, line + 1);
		else
			*val = ft_atoi(line);
	}
}
