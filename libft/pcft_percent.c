/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pcft_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:02:26 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 11:02:28 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		pcft_percent(t_conv *cd)
{
	char	*str;
	int		ret;
	int		pad;
	char	padc;

	str = "%";
	padc = ' ';
	if (cd->zero)
		padc = '0';
	ret = ft_strlen(str);
	if (cd->width_given)
	{
		pad = cd->width > ret ? cd->width - ret : 0;
		if (!cd->left_align)
			ft_putstrpad_fd("", pad, padc, cd->fd);
	}
	ft_putnstr_fd(str, ret, cd->fd);
	if (cd->width_given && cd->left_align)
		ft_putstrpad_fd("", pad, padc, cd->fd);
	if (cd->width_given)
		ret += pad;
	return (ret);
}
