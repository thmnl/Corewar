/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:08:24 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/14 16:24:57 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_champ		*ft_bad_label(char *s, t_champ *f, int l)
{
	l++;
	ft_putstr("\x1b[138;1;31m");
	ft_printf("%s: Bad label for instruction %s ligne %d\n", f->path, s, l);
	ft_putstr("\x1B[0m");
	f->error = 1;
	return (f);
}
