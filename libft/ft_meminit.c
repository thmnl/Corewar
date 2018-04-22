/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_meminit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:31:00 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:31:01 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_meminit(size_t size, char c)
{
	char	*temp;
	size_t	i;

	i = 0;
	if (size < 1)
		return (NULL);
	temp = (char*)safe_malloc(size);
	if (!temp)
		return (NULL);
	while (i < size)
		temp[i++] = c;
	return ((void*)temp);
}
