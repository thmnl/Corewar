/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ini.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:36:09 by brocher           #+#    #+#             */
/*   Updated: 2018/04/09 13:36:13 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_struct.h"
#include "vm_proto.h"
#include "errors.h"

void	fill_useful_all(t_op *op_tab)
{
	fill_useful(&(op_tab[0]), 10, 0, 0);
	fill_useful(&(op_tab[1]), 5, 1, 0);
	fill_useful(&(op_tab[2]), 5, 1, 0);
	fill_useful(&(op_tab[3]), 10, 1, 0);
	fill_useful(&(op_tab[4]), 10, 1, 0);
	fill_useful(&(op_tab[5]), 6, 1, 0);
	fill_useful(&(op_tab[6]), 6, 1, 0);
	fill_useful(&(op_tab[7]), 6, 1, 0);
	fill_useful(&(op_tab[8]), 20, 0, 1);
	fill_useful(&(op_tab[9]), 25, 1, 1);
	fill_useful(&(op_tab[10]), 25, 1, 1);
	fill_useful(&(op_tab[11]), 800, 0, 1);
	fill_useful(&(op_tab[12]), 10, 1, 0);
	fill_useful(&(op_tab[13]), 50, 1, 1);
	fill_useful(&(op_tab[14]), 1000, 0, 1);
	fill_useful(&(op_tab[15]), 2, 1, 0);
}

void	fill_text_all(t_op *op_tab)
{
	fill_text(&(op_tab[0]), "live", "alive");
	fill_text(&(op_tab[1]), "ld", "load");
	fill_text(&(op_tab[2]), "st", "store");
	fill_text(&(op_tab[3]), "add", "addition");
	fill_text(&(op_tab[4]), "sub", "soustraction");
	fill_text(&(op_tab[5]), "and", "et (and r1, r2, r3  r1&r2 -> r3");
	fill_text(&(op_tab[6]), "or", "ou (or r1, r2, r3  r1 | r2 -> r3");
	fill_text(&(op_tab[7]), "xor", "ou (xor r1, r2, r3  r1^r2 -> r3");
	fill_text(&(op_tab[8]), "zjmp", "jump if zero");
	fill_text(&(op_tab[9]), "ldi", "load index");
	fill_text(&(op_tab[10]), "sti", "store index");
	fill_text(&(op_tab[11]), "fork", "fork");
	fill_text(&(op_tab[12]), "lld", "long load");
	fill_text(&(op_tab[13]), "lldi", "long load index");
	fill_text(&(op_tab[14]), "lfork", "long fork");
	fill_text(&(op_tab[15]), "aff", "aff");
}

void	fill_other_all(t_op *op_tab)
{
	fill_other(&(op_tab[0]), 1, 1);
	fill_other(&(op_tab[1]), 2, 2);
	fill_other(&(op_tab[2]), 2, 3);
	fill_other(&(op_tab[3]), 3, 4);
	fill_other(&(op_tab[4]), 3, 5);
	fill_other(&(op_tab[5]), 3, 6);
	fill_other(&(op_tab[6]), 3, 7);
	fill_other(&(op_tab[7]), 3, 8);
	fill_other(&(op_tab[8]), 1, 9);
	fill_other(&(op_tab[9]), 3, 10);
	fill_other(&(op_tab[10]), 3, 11);
	fill_other(&(op_tab[11]), 1, 12);
	fill_other(&(op_tab[12]), 2, 13);
	fill_other(&(op_tab[13]), 3, 14);
	fill_other(&(op_tab[14]), 1, 15);
	fill_other(&(op_tab[15]), 1, 16);
}

void	fill_type_all(t_op *op_tab)
{
	fill_type_u(&(op_tab[0]), 4, 0, 0);
	fill_type_u(&(op_tab[1]), 4 + 2, 1, 0);
	fill_type_u(&(op_tab[2]), 1, 2 + 1, 0);
	fill_type_u(&(op_tab[3]), 1, 1, 1);
	fill_type_u(&(op_tab[4]), 1, 1, 1);
	fill_type_u(&(op_tab[5]), 1 + 2 + 4, 1 + 2 + 4, 1);
	fill_type_u(&(op_tab[6]), 1 + 2 + 4, 1 + 2 + 4, 1);
	fill_type_u(&(op_tab[7]), 1 + 2 + 4, 1 + 2 + 4, 1);
	fill_type_u(&(op_tab[8]), 4, 0, 0);
	fill_type_u(&(op_tab[9]), 1 + 2 + 4, 4 + 1, 1);
	fill_type_u(&(op_tab[10]), 1, 1 + 2 + 4, 4 + 1);
	fill_type_u(&(op_tab[11]), 4, 0, 0);
	fill_type_u(&(op_tab[12]), 2 + 4, 1, 0);
	fill_type_u(&(op_tab[13]), 1 + 2 + 4, 4 + 1, 1);
	fill_type_u(&(op_tab[14]), 4, 0, 0);
	fill_type_u(&(op_tab[15]), 1, 0, 0);
}

t_op	*ini_op_tab(void)
{
	t_op	*op_tab;

	op_tab = (t_op *)safe_malloc(sizeof(t_op) * 16);
	fill_useful_all(op_tab);
	fill_text_all(op_tab);
	fill_type_all(op_tab);
	fill_other_all(op_tab);
	return (op_tab);
}
