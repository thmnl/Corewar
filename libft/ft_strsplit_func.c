/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:54:44 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:54:47 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	sft_count_res_len(char *split_index, size_t len)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (i < len)
	{
		while (i < len && split_index[i])
			i++;
		if (i != len)
			count++;
		while (i < len && !split_index[i])
			i++;
	}
	return (count);
}

static void		sft_fill_result(char **result, char *si, char *str, size_t len)
{
	int		j;
	size_t	i;
	size_t	k;

	i = 0;
	j = 0;
	while (i < len)
	{
		while (i < len && si[i])
			i++;
		if (i != len)
		{
			k = i;
			while (k < len && !si[k])
				k++;
			result[j++] = ft_strsub(str, i, k - i);
		}
		while (i < len && !si[i])
			i++;
	}
	result[j] = NULL;
}

static void		sft_fill_index(char *splt_ind, char *str, int (*fp)(char*, int))
{
	int i;

	i = 0;
	while (str[i])
	{
		splt_ind[i] = fp(str, i);
		i++;
	}
}

char			**ft_strsplit_func(char *str, int (*fp)(char*, int))
{
	char	*split_index;
	char	**result;
	size_t	res_len;

	if (!str || !fp || !(split_index = (char*)safe_malloc(ft_strlen(str))))
		return (NULL);
	sft_fill_index(split_index, str, fp);
	res_len = sft_count_res_len(split_index, ft_strlen(str));
	if (!(result = (char**)safe_malloc(sizeof(char*) * (res_len + 1))))
		return (NULL);
	sft_fill_result(result, split_index, str, ft_strlen(str));
	free(split_index);
	return (result);
}
