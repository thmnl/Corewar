/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwnstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:44:23 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:44:24 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putwnstr(wchar_t *wstr, size_t n)
{
	size_t i;
	size_t ret;

	i = 0;
	ret = 0;
	while (wstr[i] && i < n)
		ret += ft_putwchar(wstr[i++]);
	return (ret);
}
