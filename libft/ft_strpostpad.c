/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpostpad.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:53:41 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:53:43 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpostpad(char *str, size_t n, char c)
{
	char	*newstr;
	size_t	i;
	size_t	size;
	size_t	sstr;

	sstr = ft_strlen(str);
	size = sstr > n ? sstr : n;
	if (!(newstr = (char*)safe_malloc(size)))
		return (NULL);
	ft_strcpy(newstr, str);
	i = sstr;
	while (i < n)
		newstr[i++] = c;
	newstr[i] = '\0';
	return (newstr);
}
