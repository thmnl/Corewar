/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_str_switch_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:05:09 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 11:05:10 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*pft_str_switch_d(va_list ap, t_conv *cd, int *sign)
{
	unsigned char	v1;
	char			*str;

	if (cd->size == 'H')
	{
		v = va_arg(unsigned char);
		if (cd->precise && cd->precision == 0 && v == 0)
			str = ft_strdup("");
		else if (!(str = ft_itoa_max_abs(v)))
			return (NULL);
		sign = 0;
	}
}
