/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:48:05 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:48:07 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdjoin(char *dest, char deli, char *src)
{
	char	*newstr;
	int		i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	if (!(newstr = (char*)safe_malloc(ft_strlen(dest) + ft_strlen(src) + 2)))
		return (NULL);
	while (*dest)
		newstr[i++] = *dest++;
	newstr[i++] = deli;
	while (*src)
		newstr[i++] = *src++;
	newstr[i] = '\0';
	return (newstr);
}
