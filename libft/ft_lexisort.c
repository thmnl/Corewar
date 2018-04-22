/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexisort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:26:01 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:26:02 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	start = starting index.
**	end = last index to check
*/

char		**ft_lexisort(char **tab, int start, int end)
{
	ft_strquicksort(tab, start, end, &ft_strcmp);
	return (tab);
}
