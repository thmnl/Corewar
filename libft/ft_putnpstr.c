/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnpstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:39:39 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:39:40 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnpstr(char **tab, int start, int end)
{
	int i;

	i = start;
	while (i <= end)
	{
		if (tab[i])
			ft_putendl(tab[i++]);
	}
}
