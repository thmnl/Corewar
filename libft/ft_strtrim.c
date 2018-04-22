/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:55:37 by brocher           #+#    #+#             */
/*   Updated: 2018/04/17 13:12:07 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		l;
	char	*str;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	while (l > 0 && (s[l - 1] == ' ' || s[l - 1] == '\t' || s[l - 1] == '\n'))
		l--;
	i = -1;
	while (s[++i] == ' ' || s[i] == '\t' || s[i] == '\n')
		l--;
	if (l <= 0)
		l = 0;
	if (l == 0)
		return (ft_strdup(""));
	str = (char*)safe_malloc(sizeof(char) * (l + 1));
	if (!str)
		return (NULL);
	s += i;
	i = -1;
	while (++i < l)
		str[i] = *s++;
	str[i] = '\0';
	return (str);
}
