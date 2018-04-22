/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adjust_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:47:39 by allallem          #+#    #+#             */
/*   Updated: 2018/01/24 16:05:34 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		reset_if_j(t_pfspe *p)
{
	p->j = 1;
	p->l = 0;
	p->h = 0;
	p->z = 0;
}

void		reset_if_z(t_pfspe *p)
{
	p->z = 1;
	p->h = 0;
}

void		reset_if_l(t_pfspe *p)
{
	if (p->l > 1)
	{
		p->l = 2;
		p->h = 0;
		p->j = 0;
		p->z = 0;
	}
	else if (p->l == 1)
	{
		p->h = 0;
		p->j = 0;
		p->z = 0;
	}
}
