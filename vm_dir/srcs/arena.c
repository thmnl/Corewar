/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 12:53:15 by brocher           #+#    #+#             */
/*   Updated: 2018/04/09 12:53:16 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_struct.h"
#include "vm_proto.h"
#include "errors.h"

void		get_from_arena(t_vm *vm, t_prc *prc, int id, int loc)
{
	int		i;

	i = 0;
	set_reg_zero(prc, id);
	while (loc < 0)
		loc += MEM_SIZE;
	while (loc > MEM_SIZE)
		loc -= MEM_SIZE;
	while (i < REG_SIZE)
	{
		prc->reg[(id - 1) * REG_SIZE + i] = vm->arn[(prc->pc \
				+ loc + i) % MEM_SIZE];
		i++;
	}
}

void		put_in_arena(t_vm *vm, int pos, char c)
{
	if (pos >= 0)
		vm->arn[pos % MEM_SIZE] = c;
	else
	{
		while (pos < 0)
			pos += MEM_SIZE;
		vm->arn[pos] = c;
	}
}

void		put_in_color(t_vm *vm, int pos, char c)
{
	if (pos >= 0)
		vm->color[pos % MEM_SIZE] = c;
	else
	{
		while (pos < 0)
			pos += MEM_SIZE;
		vm->color[pos] = c;
	}
}

void		put_in_highlight(t_vm *vm, int pos, char c)
{
	if (pos >= 0)
		vm->highlight[pos % MEM_SIZE] = c;
	else
	{
		while (pos < 0)
			pos += MEM_SIZE;
		vm->highlight[pos] = c;
	}
}
