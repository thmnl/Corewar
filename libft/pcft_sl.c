/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pcft_sl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:02:53 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 11:02:54 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		pcft_sl(va_list ap, t_conv *cd)
{
	wchar_t	*str;
	int		ret;
	int		pad;

	str = va_arg(ap, wchar_t*);
	if (!str)
		str = L"(null)";
	ret = ft_wstrlen(str);
	if (cd->precise && cd->precision < ret)
		ret = cd->precision;
	if (cd->width_given)
	{
		pad = cd->width > ret ? cd->width - ret : 0;
		if (!cd->left_align)
			ft_putstrpad_fd("", pad, ' ', cd->fd);
	}
	ft_putwnstr_fd(str, ret, cd->fd);
	if (cd->width_given && cd->left_align)
		ft_putstrpad_fd("", pad, ' ', cd->fd);
	if (cd->width_given)
		ret += pad;
	return (ret);
}
