/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strquicksort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:54:07 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:54:08 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strquicksort(
char **sort, int start, int end, int fp(const char*, const char*))
{
	int		i;
	int		j;
	char	*pivot;
	char	*swap;

	i = start;
	j = end;
	pivot = sort[(start + end) / 2];
	while (i <= j)
	{
		while (fp(pivot, sort[i]) > 0)
			++i;
		while (fp(pivot, sort[j]) < 0)
			--j;
		if (i <= j)
		{
			swap = sort[i];
			sort[i++] = sort[j];
			sort[j--] = swap;
		}
	}
	if (start < j)
		ft_strquicksort(sort, start, j, fp);
	if (end > i)
		ft_strquicksort(sort, i, end, fp);
}
