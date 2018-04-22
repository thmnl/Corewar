/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_pstr_range.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:45:30 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:45:32 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_remove_pstr_range(char **src, int start, int end)
{
	int		len;
	int		len_src;
	char	**result;
	int		i;
	int		j;

	len_src = ft_countpstr(src);
	if (len_src <= end)
		end = len_src - 1;
	len = len_src - (end - start + 1);
	if (start < 0 || end < 0 || len < 1)
		return (NULL);
	if (!(result = (char**)safe_malloc(sizeof(char*) * len + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (src[i])
	{
		if (i < start || i > end)
			result[j++] = ft_strdup(src[i]);
		i++;
	}
	result[j] = NULL;
	return (result);
}
