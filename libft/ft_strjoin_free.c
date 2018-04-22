/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:14:28 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/09 13:42:25 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, size_t n)
{
	char	*tab;

	if (!(tab = ft_strjoin((const char*)s1, (const char*)s2)))
		return (NULL);
	if (n == 1 || n == 3)
		free(s1);
	if (n == 2 || n == 3)
		free(s2);
	return (tab);
}
