/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:50:19 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:50:25 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	newstr = (char*)safe_malloc(len + 1);
	if (!newstr)
		return (NULL);
	ft_memset(newstr, '.', (size_t)len);
	newstr[len] = '\0';
	ft_strcpy(newstr, s1);
	newstr = ft_strcat(newstr, s2);
	return (newstr);
}
