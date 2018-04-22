/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pcft_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:02:10 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 11:02:11 by brocher          ###   ########.fr       */
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
		tstr = ft_strjoin("0X", str);
		free(str);
		str = tstr;
	}
	return (str);
}

static int		pcft_p2(t_conv *cd, char *str, int less, char padc)
{
	int ret;

	if (!cd->zero || cd->precise)
		str = spft_handle_special(str, less);
	if (cd->zero && !cd->precise)
		str = spft_handle_width(cd, padc, str, less);
	else
		str = spft_handle_width(cd, padc, str, 0);
	if (cd->zero && !cd->precise)
		str = spft_handle_special(str, less);
	ft_strtolower(str);
	if (!str)
		return (-1);
	ft_putstr_fd(str, cd->fd);
	ret = ft_strlen(str);
	free(str);
	return (ret);
}

int				pcft_p(va_list ap, t_conv *cd)
{
	void			*v;
	char			*str;
	char			padc;
	int				less;

	v = va_arg(ap, void*);
	if (cd->precise && cd->precision == 0 && v == NULL)
		str = ft_strdup("");
	else if (!(str = ft_itoabase_max_abs((uintmax_t)v, 16)))
		return (-1);
	less = 2;
	padc = ' ';
	if (cd->zero && !cd->left_align && !cd->precise)
		padc = '0';
	str = spft_handle_precision(cd, str);
	return (pcft_p2(cd, str, less, padc));
}
