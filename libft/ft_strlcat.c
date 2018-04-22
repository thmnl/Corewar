/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:50:36 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:50:38 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t a;

	i = 0;
	a = 0;
	while (dest[i] && i < size)
		i++;
	while (src[a] && (i + a) < (size - 1))
	{
		dest[i + a] = src[a];
		a++;
	}
	if (i < size)
		dest[i + a] = 0;
	return (i + ft_strlen(src));
}
