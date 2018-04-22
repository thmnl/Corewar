/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_parse_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:04:45 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 11:04:47 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		spft_isin(char c, char *format, size_t start, size_t end)
{
	while (start < end)
	{
		if (format[start] == c)
			return (1);
		start++;
	}
	return (0);
}

static void		spft_getwp(
t_conv *convdata, char *format, size_t start, size_t end)
{
	int i;

	i = 0;
	while (i + start < end)
	{
		if (ft_isdigit(format[i + start]) && format[i + start] != '0')
		{
			if (format[i + start - 1] == '.')
				convdata->precision = ft_atoi(format + start + i);
			else
			{
				convdata->width_given = 1;
				convdata->width = ft_atoi(format + start + i);
			}
			while (ft_isdigit(format[i + start]))
				i++;
		}
		i++;
	}
}

static void		spft_getsize(
t_conv *convdata, char *format, size_t start, size_t end)
{
	char c;

	while (start < end - 1)
	{
		c = format[start];
		if (c == 'j' || c == 'z' || c == 'h' || c == 'l')
			convdata->size = c;
		if (convdata->size == 'h' && format[start + 1] == 'h')
			convdata->size = 'H';
		else if (convdata->size == 'l' && format[start + 1] == 'l')
			convdata->size = 'L';
		if (convdata->size)
			return ;
		start++;
	}
}

static void		spft_get_zero(t_conv *cd, char *f, int s, int end)
{
	while (f[s] && s < end)
	{
		if (f[s] == '0' && !ft_isdigit(f[s - 1]) && f[s - 1] != '.')
			cd->zero = 1;
		s++;
	}
}

int				pft_parse_conv(
char *format, size_t se[3], va_list ap, t_conv *cd)
{
	if (format[se[1]] != '%' || se[0] - 1 == se[1])
		return (0);
	if (!(pft_isconv(cd->type = format[se[0] - 1])))
		return (0);
	spft_convdata_init(cd);
	if (spft_isin('-', format, se[1], se[0]))
		cd->left_align = 1;
	if (spft_isin('+', format, se[1], se[0]))
		cd->posit_show = 1;
	if (spft_isin(' ', format, se[1], se[0]))
		cd->space = 1;
	if (spft_isin('#', format, se[1], se[0]))
		cd->special = 1;
	if (spft_isin('.', format, se[1], se[0]))
		cd->precise = 1;
	spft_get_zero(cd, format, se[1], se[0]);
	spft_getwp(cd, format, se[1], se[0]);
	spft_getsize(cd, format, se[1], se[0]);
	pft_mod_conv(cd);
	return (pft_fconv(ap, cd, 42));
}
