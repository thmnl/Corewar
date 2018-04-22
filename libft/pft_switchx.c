/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_switchx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:05:54 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 11:05:55 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		pft_switchx(va_list ap, t_conv *cd)
{
	if (cd->size == 'H')
		return (pcft_hhx(ap, cd));
	if (cd->size == 'h')
		return (pcft_hx(ap, cd));
	if (cd->size == 'l')
		return (pcft_lx(ap, cd));
	if (cd->size == 'L')
		return (pcft_llx(ap, cd));
	if (cd->size == 'j')
		return (pcft_jx(ap, cd));
	if (cd->size == 'z')
		return (pcft_zx(ap, cd));
	return (pcft_x(ap, cd));
}
