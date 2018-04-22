/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ini_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:36:21 by brocher           #+#    #+#             */
/*   Updated: 2018/04/09 13:36:22 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_struct.h"
#include "vm_proto.h"
#include "errors.h"

void	fill_useful(t_op *op, int cycle, char encoding, char size)
{
	op->cycle = cycle;
	op->encoding = encoding;
	op->size = size;
}

void	fill_text(t_op *op, char *name, char *comment)
{
	op->name = ft_strdup(name);
	if (op->name == NULL)
		error("out of memory", NULL);
	op->comment = ft_strdup(comment);
	if (op->comment == NULL)
		error("out of memory", NULL);
}

void	fill_other(t_op *op_tab, char nb_param, char op)
{
	op_tab->nb_param = nb_param;
	op_tab->op = op;
}

void	fill_type_u(t_op *op_tab, char t0, char t1, char t2)
{
	(op_tab->type)[0] = t0;
	(op_tab->type)[1] = t1;
	(op_tab->type)[2] = t2;
}
