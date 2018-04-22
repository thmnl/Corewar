/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addpstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:15:15 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:15:16 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_addpstr(char *str, char **arr)
{
	char	**newarr;
	char	*joiner[2];

	if (!str || !arr)
		return (arr);
	joiner[0] = str;
	joiner[1] = NULL;
	newarr = ft_joinpstr(arr, joiner);
	return (newarr);
}
