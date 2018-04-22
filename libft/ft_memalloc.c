/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:29:26 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:29:27 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
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
		temp[i++] = '\0';
	return ((void*)temp);
}
