/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pcft_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:02:44 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 11:02:45 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		pcft_s(va_list ap, t_conv *cd)
{
	char	*str;
	int		ret;
	int		pad;

	str = va_arg(ap, char*);
	if (!str)
		str = "(null)";
	ret = ft_strlen(str);
	if (cd->precise && cd->precision < ret)
		ret = cd->precision;
	if (cd->width_given)
	{
		pad = cd->width > ret ? cd->width - ret : 0;
		if (!cd->left_align)
			ft_putstrpad_fd("", pad, ' ', cd->fd);
	}
	ft_putnstr_fd(str, ret, cd->fd);
	if (cd->width_given && cd->left_align)
		ft_putstrpad_fd("", pad, ' ', cd->fd);
	if (cd->width_given)
		ret += pad;
	return (ret);
}
