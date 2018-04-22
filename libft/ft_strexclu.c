/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strexclu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:48:47 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:49:25 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** return true if all the characters is the 1st str are also in the 2nd str.
*/

#include "libft.h"

int	ft_strexclu(const char *str, const char *ref)
{
	size_t	i;
	size_t	j;
	int		in;

	i = 0;
	while (str[i])
	{
		j = 0;
		in = 0;
		while (ref[j])
		{
			if (str[i] == ref[j])
				in = 1;
			j++;
		}
		if (!in)
			return (0);
		i++;
	}
	return (1);
}
