/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_parse_conv2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:04:57 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 11:04:58 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		spft_convdata_init(t_conv *convdata)
{
	convdata->left_align = 0;
	convdata->posit_show = 0;
	convdata->space = 0;
	convdata->precision = 0;
	convdata->zero = 0;
	convdata->special = 0;
	convdata->width = 0;
	convdata->width_given = 0;
	convdata->precise = 0;
	convdata->size = '\0';
}

void		pft_mod_conv(t_conv *cd)
{
	if (cd->type == 's' && cd->size == 'l')
		cd->type = 'S';
	else if (cd->type == 'c' && cd->size == 'l')
		cd->type = 'C';
	else if (cd->type == 'i')
		cd->type = 'd';
	else if (cd->type == 'O')
	{
		cd->type = 'o';
		cd->size = 'l';
	}
	else if (cd->type == 'U')
	{
		cd->type = 'u';
		cd->size = 'l';
	}
	else if (cd->type == 'D')
	{
		cd->type = 'd';
		cd->size = 'l';
	}
}

int			pft_fconv(va_list ap, t_conv *convdata, int ret)
{
	ret = 0;
	if (convdata->type == 's')
		ret = pcft_s(ap, convdata);
	else if (convdata->type == '%')
		ret = pcft_percent(convdata);
	else if (convdata->type == 'S')
		ret = pcft_sl(ap, convdata);
	else if (convdata->type == 'd')
		ret = pft_switchd(ap, convdata);
	else if (convdata->type == 'c')
		ret = pcft_c(ap, convdata);
	else if (convdata->type == 'C')
		ret = pcft_lc(ap, convdata);
	else if (convdata->type == 'x' || convdata->type == 'X')
		ret = pft_switchx(ap, convdata);
	else if (convdata->type == 'o')
		ret = pft_switcho(ap, convdata);
	else if (convdata->type == 'u')
		ret = pft_switchu(ap, convdata);
	else if (convdata->type == 'p')
		ret = pcft_p(ap, convdata);
	else if (convdata->type == 'y')
		ret = pcft_y(ap, convdata);
	return (ret);
}
