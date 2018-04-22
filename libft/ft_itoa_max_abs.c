/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_max_abs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:24:06 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:24:08 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

static void		sft_isneg(intmax_t *n)
{
	if (*n < 0)
		*n *= -1;
}

char			*ft_itoa_max_abs(intmax_t n)
{
	char		*str;
	int			len;
	intmax_t	nc;

	if (n == INTMAX_MIN)
		return (ft_strdup("9223372036854775808"));
	len = 2;
	sft_isneg(&n);
	nc = n;
	while (nc /= 10)
		len++;
	if (!(str = (char*)safe_malloc(len)))
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
