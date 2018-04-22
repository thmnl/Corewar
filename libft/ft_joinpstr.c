/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinpstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:25:46 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:25:47 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_joinpstr(char **arr1, char **arr2)
{
	int		len;
	char	**newarr;
	int		i;

	len = ft_countpstr(arr1) + ft_countpstr(arr2) + 1;
	if (!(newarr = (char**)safe_malloc(sizeof(char*) * len)))
		return (NULL);
	newarr[len - 1] = NULL;
	i = 0;
	while (*arr1)
		newarr[i++] = ft_strdup(*arr1++);
	while (*arr2)
		newarr[i++] = ft_strdup(*arr2++);
	return (newarr);
}
