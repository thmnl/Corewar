/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:44:58 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:45:00 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putwstr(wchar_t *wstr)
{
	size_t i;
	size_t ret;

	i = 0;
	ret = 0;
	while (wstr[i])
		ret += ft_putwchar(wstr[i++]);
	return (ret);
}
