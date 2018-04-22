/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:56:31 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:56:32 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wstrlen(wchar_t *wstr)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	while (wstr[i])
		count += ft_wcharlen(wstr[i++]);
	return (count);
}
