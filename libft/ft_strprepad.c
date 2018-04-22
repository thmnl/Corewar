/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprepad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:53:56 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:53:58 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strprepad(char *str, size_t n, char c)
{
	char	*newstr;
	size_t	i;
	size_t	size;
	size_t	sstr;

	sstr = ft_strlen(str);
	size = sstr > n ? sstr : n;
	if (!(newstr = (char*)safe_malloc(size)))
		return (NULL);
	i = 0;
	while (i + sstr < n)
		newstr[i++] = c;
	ft_strcpy(newstr + i, str);
	return (newstr);
}
