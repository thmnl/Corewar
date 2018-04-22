/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:29:49 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:29:50 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	target;
	unsigned char	*src;

	src = (unsigned char*)str;
	target = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (src[i] == target)
		{
			return ((void*)src + i);
		}
		i++;
	}
	return (NULL);
}
