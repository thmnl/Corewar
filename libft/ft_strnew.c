/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:53:09 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:53:10 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	str = (char*)safe_malloc(size + 1);
	if (!str)
		return (NULL);
	while (size + 1)
	{
		str[size--] = '\0';
	}
	return (str);
}
