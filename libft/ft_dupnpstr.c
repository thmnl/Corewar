/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dupnpstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:17:58 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:17:59 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_dupnpstr(char **src, int len)
{
	char	**new;
	int		i;

	if (!(new = (char**)safe_malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	i = 0;
	while (src[i] && i < len)
	{
		new[i] = ft_strdup(src[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}
