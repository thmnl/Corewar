/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_pstr_func.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:45:14 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:45:15 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_remove_pstr_func(char **src, int (*filter)(char*))
{
	char	**rest;
	char	**temp_buffer;
	int		i;
	int		j;

	if (!(temp_buffer = (char**)safe_malloc(sizeof(char*) * ft_countpstr(src))))
		return (NULL);
	i = 0;
	j = 0;
	while (src[i])
	{
		if (!filter(src[i]))
			temp_buffer[j++] = ft_strdup(src[i]);
		i++;
	}
	rest = ft_dupnpstr(temp_buffer, j);
	i = 0;
	while (i < j)
		free(temp_buffer[i++]);
	free(temp_buffer);
	return (rest);
}
