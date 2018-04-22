/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splittrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 18:22:14 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/17 13:14:43 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_splittrim(char *s, char c)
{
	char	**ret;
	char	*tmp;
	int		i;

	i = 0;
	if (!(ret = ft_strsplit(s, c)))
		return (NULL);
	while (ret[i])
	{
		tmp = ft_strtrim(ret[i]);
		ft_strdel(&ret[i]);
		ret[i] = ft_strdup(tmp);
		ft_strdel(&tmp);
		i++;
	}
	return (ret);
}
