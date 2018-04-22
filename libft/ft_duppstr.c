/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duppstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:18:37 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:18:38 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_duppstr(char **arr)
{
	int		len;
	char	**newarr;

	len = ft_countpstr(arr);
	if (!(newarr = (char**)safe_malloc(sizeof(char*) * len + 1)))
		return (NULL);
	newarr[len--] = NULL;
	while (len >= 0)
	{
		newarr[len] = ft_strdup(arr[len]);
		len--;
	}
	return (newarr);
}
