/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:37:26 by brocher           #+#    #+#             */
/*   Updated: 2018/04/09 13:37:28 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_struct.h"
#include "vm_proto.h"
#include "errors.h"

void		fill_int(char *addr, int nb, char size)
{
	char	i;
	char	byte;
	int		tmp;

	i = 0;
	while (i < size)
	{
		tmp = nb & 0x000000FF;
		byte = (char)(tmp);
		nb = nb & 0xFFFFFF00;
		nb = nb >> 8;
		addr[size - 1 - i++] = byte;
	}
}

char		reg_size_check(int nb)
{
	int		cmp;

	cmp = 0;
	if (REG_SIZE >= 4)
		return (1);
	else if (REG_SIZE == 3)
		cmp = 0xFF000000;
	else if (REG_SIZE == 2)
		cmp = 0xFFFF0000;
	else if (REG_SIZE == 1)
		cmp = 0xFFFFFF00;
	else if (REG_SIZE == 0)
		return (0);
	if ((cmp & nb) == 0x00000000)
		return (1);
	return (0);
}

int			get_from_reg(t_prc *prc, int id)
{
	int		nb;
	int		i;
	int		tmp;

	nb = 0;
	i = 0;
	while (i < REG_SIZE)
	{
		nb = nb << 8;
		tmp = (int)(prc->reg[(id - 1) * REG_SIZE + i]);
		tmp = tmp & 0x000000FF;
		nb = nb | tmp;
		i++;
	}
	return (nb);
}

void		set_reg_zero(t_prc *prc, int id)
{
	ft_memset(&(prc->reg[(id - 1) * REG_SIZE]), 0, REG_SIZE);
}

void		put_in_reg(t_prc *prc, int id, int nb)
{
	set_reg_zero(prc, id);
	if (reg_size_check(nb))
		fill_int(&(prc->reg[(id - 1) * REG_SIZE]), nb, REG_SIZE);
	else
		error("could not update registery, increase registery size", NULL);
}
