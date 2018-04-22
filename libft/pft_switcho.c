/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_switcho.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:05:35 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 11:05:36 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		pft_switcho(va_list ap, t_conv *cd)
{
	if (cd->size == 'H')
		return (pcft_hho(ap, cd));
	if (cd->size == 'h')
		return (pcft_ho(ap, cd));
	if (cd->size == 'l')
		return (pcft_lo(ap, cd));
	if (cd->size == 'L')
		return (pcft_llo(ap, cd));
	if (cd->size == 'j')
		return (pcft_jo(ap, cd));
	if (cd->size == 'z')
		return (pcft_zo(ap, cd));
	return (pcft_o(ap, cd));
}
