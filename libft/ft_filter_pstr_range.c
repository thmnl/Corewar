/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filter_pstr_range.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:20:05 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:20:07 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_filter_pstr_range(char **pstr, int start, int end)
{
	int		len;
	char	**result;
	int		len_ofsrc;
	int		i;
	int		j;

	len = end - start + 1;
	if (start < 0 || end < 0 || len < 1)
		return (NULL);
	len_ofsrc = ft_countpstr(pstr);
	if (len_ofsrc <= end)
		end = len_ofsrc - 1;
	if (!(result = (char**)safe_malloc(sizeof(char*) * len + 1)))
		return (NULL);
	i = start;
	j = 0;
	while (i <= end)
		result[j++] = ft_strdup(pstr[i++]);
	result[j] = NULL;
	return (result);
}
