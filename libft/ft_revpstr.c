/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revpstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:45:45 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:45:47 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_revpstr(char **tab, int start, int end)
{
	char	*swap;

	if (!tab)
		return ;
	while (end > start)
	{
		swap = tab[start];
		tab[start++] = tab[end];
		tab[end--] = swap;
	}
}
