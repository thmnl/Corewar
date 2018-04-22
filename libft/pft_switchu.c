/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_switchu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:05:45 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 11:05:46 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		pft_switchu(va_list ap, t_conv *cd)
{
	if (cd->size == 'H')
		return (pcft_hhu(ap, cd));
	if (cd->size == 'h')
		return (pcft_hu(ap, cd));
	if (cd->size == 'l')
		return (pcft_lu(ap, cd));
	if (cd->size == 'L')
		return (pcft_llu(ap, cd));
	if (cd->size == 'j')
		return (pcft_ju(ap, cd));
	if (cd->size == 'z')
		return (pcft_zu(ap, cd));
	return (pcft_u(ap, cd));
}
