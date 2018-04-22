/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_label_address.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 02:43:44 by allallem          #+#    #+#             */
/*   Updated: 2018/04/18 04:57:27 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	ft_check_command2(char *str)
{
	if (!ft_strncmp(str, "zjmp", 4) || !ft_strncmp(str, "ldi", 3) ||
	!ft_strncmp(str, "lldi", 4) || !ft_strncmp(str, "lfork", 5) ||
	!ft_strncmp(str, "fork", 4) || !ft_strncmp(str, "sti", 3))
		return (2);
	else if (!ft_strncmp(str, "live", 4) || !ft_strncmp(str, "ld", 2) ||
	!ft_strncmp(str, "st", 2) || !ft_strncmp(str, "add", 3) ||
	!ft_strncmp(str, "sub", 3) || !ft_strncmp(str, "and", 3) ||
	!ft_strncmp(str, "or", 2) || !ft_strncmp(str, "xor", 3) ||
	!ft_strncmp(str, "lld", 3) || !ft_strncmp(str, "aff", 3))
		return (4);
	return (0);
}

static int	ft_check_command(char *str)
{
	if (!ft_strncmp(str, "ld", 2) || !ft_strncmp(str, "st", 2) ||
	!ft_strncmp(str, "add", 3) || !ft_strncmp(str, "sub", 3) ||
	!ft_strncmp(str, "and", 3) || !ft_strncmp(str, "or", 2) ||
	!ft_strncmp(str, "xor", 3) || !ft_strncmp(str, "ldi", 3) ||
	!ft_strncmp(str, "lld", 3) || !ft_strncmp(str, "lldi", 4) ||
	!ft_strncmp(str, "aff", 3))
		return (1);
	return (0);
}

static int	ft_count_octet_line2(char *str, int dir)
{
	char	**tab;
	int		i;
	int		value;

	value = 1;
	i = 0;
	tab = ft_strsplit(str + ft_jump_pattern(str), ',');
	tab = ft_trim(tab);
	while (tab[i])
	{
		if (tab[i][0] == '%')
			value += dir;
		else if (tab[i][0] == 'r')
			value += 1;
		else
			value += 2;
		i++;
	}
	ft_free_tab(tab);
	return (value);
}

static int	ft_count_octet_line(char *str)
{
	int octet;
	int i;
	int j;

	i = 0;
	octet = 0;
	if (ft_check_ist(str))
		i += ft_count_label_char(str, 1);
	octet += ft_check_command(str + i);
	j = ft_check_command2(str + i);
	if (j > 0)
		octet += ft_count_octet_line2(str + i, j);
	return (octet);
}

int			ft_get_label_address(t_champ *p, int ist, int label)
{
	int c;

	p->label[label]->address = 0;
	c = 0;
	while (c < ist)
	{
		p->label[label]->address += ft_count_octet_line(p->ist[c]);
		c++;
	}
	return (1);
}
