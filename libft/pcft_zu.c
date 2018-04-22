/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pcft_zu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:04:17 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 11:04:18 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*spft_handle_width(t_conv *cd, char padc, char *str)
{
	char	*tstr;

	if (cd->width_given)
	{
		if (!cd->left_align)
			tstr = ft_strprepad(str, cd->width, padc);
		else
			tstr = ft_strpostpad(str, cd->width, padc);
		free(str);
		str = tstr;
	}
	return (str);
}

static char		*spft_handle_precision(t_conv *cd, char *str)
{
	char	*tstr;

	if (cd->precise)
	{
		tstr = ft_strprepad(str, cd->precision, '0');
		free(str);
		str = tstr;
	}
	return (str);
}

int				pcft_zu(va_list ap, t_conv *cd)
{
	size_t			v;
	char			*str;
	char			padc;
	int				ret;

	v = (size_t)va_arg(ap, uintmax_t);
	if (cd->precise && cd->precision == 0 && v == 0)
		str = ft_strdup("");
	else if (!(str = ft_itoa_umax_abs(v)))
		return (-1);
	padc = ' ';
	if (cd->zero && !cd->left_align && !cd->precise)
		padc = '0';
	if (!(str = spft_handle_precision(cd, str)))
		return (-1);
	if (!(str = spft_handle_width(cd, padc, str)))
		return (-1);
	if (!str)
		return (-1);
	ft_putstr_fd(str, cd->fd);
	ret = ft_strlen(str);
	free(str);
	return (ret);
}
