/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recup_label.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 20:25:31 by allallem          #+#    #+#             */
/*   Updated: 2018/04/19 11:26:50 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	ft_put_name_in_label(t_champ *p, int l, int j)
{
	int i;
	int k;

	i = 0;
	k = ft_count_label_char(p->ist[l], 0);
	if (!(p->label[j]->name = malloc(sizeof(char) * (k + 1))))
		ft_exit("Malloc error");
	p->label[j]->name[k] = '\0';
	while (i < k)
	{
		p->label[j]->name[i] = p->ist[l][i];
		i++;
	}
	ft_get_label_address(p, l, j);
	return (1);
}

int			ft_check_ist(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != ':')
		i++;
	if (str[i] == ':')
		return (1);
	return (0);
}

static int	ft_get_label_name(t_champ *p)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (p->ist[i])
	{
		if (ft_check_ist(p->ist[i]))
		{
			ft_put_name_in_label(p, i, j);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_count_label(t_champ *p)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (p->ist[i])
	{
		count += ft_check_ist(p->ist[i]);
		i++;
	}
	return (count);
}

int			ft_recup_label(t_champ *p)
{
	int i;

	i = ft_count_label(p);
	if (i == 0)
		return (0);
	if (!(p->label = malloc(sizeof(t_label*) * (i + 1))))
		ft_exit("Malloc error");
	p->label[i--] = NULL;
	while (i > -1)
	{
		if (!(p->label[i] = malloc(sizeof(t_label))))
			ft_exit("Malloc error");
		i--;
	}
	if (!ft_get_label_name(p))
		ft_exit("Malloc error");
	return (1);
}
