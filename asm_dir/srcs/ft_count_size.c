/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 17:57:47 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/15 18:12:34 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_champ			*ft_reg_size(t_champ *f)
{
	f->size += 1;
	return (f);
}

t_champ			*ft_dir_size(t_champ *f, char *s)
{
	if (ft_strstr(s, "fork") || ft_strstr(s, "zjmp") || ft_strstr(s, "ldi") ||
			ft_strstr(s, "sti"))
		f->size += 2;
	else
		f->size += 4;
	return (f);
}

t_champ			*ft_ind_size(t_champ *f)
{
	f->size += 2;
	return (f);
}
