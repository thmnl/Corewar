/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pcft_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:57:21 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:57:22 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		pcft_c(va_list ap, t_conv *cd)
{
	char	c;
	int		ret;
	int		pad;
	char	padc;

	c = (char)va_arg(ap, int);
	ret = 1;
	padc = ' ';
	if (cd->zero)
		padc = '0';
	if (cd->width_given)
	{
		pad = cd->width > ret ? cd->width - ret : 0;
		if (!cd->left_align)
			ft_putstrpad_fd("", pad, padc, cd->fd);
	}
	ft_putchar_fd(c, cd->fd);
	if (cd->width_given && cd->left_align)
		ft_putstrpad_fd("", pad, padc, cd->fd);
	if (cd->width_given)
		ret += pad;
	return (ret);
}
