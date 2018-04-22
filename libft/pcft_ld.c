/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pcft_ld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:00:17 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 11:00:18 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*spft_precipad(char *str, long int value, t_conv *cd)
{
	char	*tstr;

	if (!str)
		return (NULL);
	if (cd->posit_show && value >= 0)
		tstr = ft_strjoin("+", str);
	else if (cd->space && value >= 0 && !cd->posit_show)
		tstr = ft_strjoin(" ", str);
	else if (value < 0)
		tstr = ft_strjoin("-", str);
	else
		tstr = ft_strdup(str);
	free(str);
	return (tstr);
}

static char		*spft_handle_width(t_conv *cd, int sign, char padc, char *str)
{
	char	*tstr;

	if (!str)
		return (NULL);
	if (cd->width_given)
	{
		if (!cd->left_align)
			tstr = ft_strprepad(str, cd->width - sign, padc);
		else
			tstr = ft_strpostpad(str, cd->width - sign, padc);
		free(str);
		str = tstr;
	}
	return (str);
}

static char		*spft_handle_precision(
t_conv *cd, char *str, long int v, int *sign)
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
	if ((cd->posit_show || cd->space || v < 0) && cd->zero)
		*sign = 1;
	if (!cd->zero)
		str = spft_precipad(str, v, cd);
	return (str);
}

int				pcft_ld(va_list ap, t_conv *cd)
{
	long int		v;
	char			*str;
	char			padc;
	int				sign;
	int				ret;

	sign = 0;
	v = (long int)va_arg(ap, intmax_t);
	if (cd->precise && cd->precision == 0 && v == 0)
		str = ft_strdup("");
	else if (!(str = ft_itoa_max_abs(v)))
		return (-1);
	padc = ' ';
	if (cd->zero && !cd->left_align && !cd->precise)
		padc = '0';
	str = spft_handle_precision(cd, str, v, &sign);
	str = spft_handle_width(cd, sign, padc, str);
	if (cd->zero)
		str = spft_precipad(str, v, cd);
	if (!str)
		return (-1);
	ft_putstr_fd(str, cd->fd);
	ret = ft_strlen(str);
	free(str);
	return (ret);
}
