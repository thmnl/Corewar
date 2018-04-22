/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pcft_hho.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:58:15 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:58:17 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*spft_handle_width(t_conv *cd, char padc, char *str, int less)
{
	char	*tstr;

	if (!str)
		return (NULL);
	if (cd->width_given)
	{
		if (!cd->left_align)
			tstr = ft_strprepad(str, cd->width - less, padc);
		else
			tstr = ft_strpostpad(str, cd->width - less, padc);
		free(str);
		str = tstr;
	}
	return (str);
}

static char		*spft_handle_precision(t_conv *cd, char *str)
{
	char	*tstr;

	if (!str)
		return (NULL);
	if (cd->precise)
	{
		tstr = ft_strprepad(str, cd->precision, '0');
		free(str);
		str = tstr;
	}
	return (str);
}

static char		*spft_handle_special(char *str, int less)
{
	char	*tstr;

	if (!str)
		return (NULL);
	if (less)
	{
		tstr = ft_strjoin("0", str);
		free(str);
		str = tstr;
	}
	return (str);
}

static int		pcft_o2(t_conv *cd, char *str, int less, char padc)
{
	int	ret;

	if (cd->zero)
		str = spft_handle_width(cd, padc, str, less);
	else
		str = spft_handle_width(cd, padc, str, 0);
	if (cd->zero)
		str = spft_handle_special(str, less);
	if (!str)
		return (-1);
	ft_putstr_fd(str, cd->fd);
	ret = ft_strlen(str);
	free(str);
	return (ret);
}

int				pcft_hho(va_list ap, t_conv *cd)
{
	unsigned char	v;
	char			*str;
	char			padc;
	int				less;

	v = (unsigned char)va_arg(ap, uintmax_t);
	less = 0;
	if (cd->precise && cd->precision == 0 && v == 0 && !cd->special)
		str = ft_strdup("");
	else if (!(str = ft_itoabase_umax_abs((uintmax_t)v, 8)))
		return (-1);
	if (cd->special && v != 0)
		less = 1;
	padc = ' ';
	if (cd->zero && !cd->left_align && !cd->precise)
		padc = '0';
	if (!cd->zero)
		str = spft_handle_special(str, less);
	str = spft_handle_precision(cd, str);
	return (pcft_o2(cd, str, less, padc));
}
