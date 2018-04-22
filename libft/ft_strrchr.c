/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:54:19 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:54:20 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned char	target;
	int				i;

	i = 0;
	target = (unsigned char)c;
	while (str[i])
		i++;
	while (i > -1)
	{
		if (((unsigned char*)str)[i] == target)
			return ((char*)(str + i));
		i--;
	}
	return (NULL);
}
