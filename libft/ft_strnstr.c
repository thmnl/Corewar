/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:53:28 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:53:30 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	int i;
	int a;

	i = 0;
	a = 0;
	if (!s2[0])
	{
		return ((char*)s1);
	}
	while (s1[i])
	{
		while (s1[i + a] == s2[a])
		{
			a++;
			if ((size_t)(i + a) > len)
				return (NULL);
			if (!s2[a])
				return ((char*)s1 + i);
		}
		a = 0;
		i++;
	}
	s1 = 0;
	return ((char*)s1);
}
