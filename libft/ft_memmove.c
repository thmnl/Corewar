/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:31:14 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:31:15 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;
	unsigned char	*temp;

	dest = (unsigned char*)str1;
	src = (unsigned char*)str2;
	temp = src;
	while (temp < src + n)
	{
		if (temp == dest)
		{
			temp = src + n - 1;
			while (temp >= src)
			{
				*(temp + (dest - src)) = *temp;
				temp--;
			}
			return (dest);
		}
		temp++;
	}
	return (ft_memcpy(str1, str2, n));
}
