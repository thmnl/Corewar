/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabasemax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 07:57:07 by dmenard           #+#    #+#             */
/*   Updated: 2017/01/06 11:19:27 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		sft_loadchar(char *str, size_t len, intmax_t value, int base)
{
	intmax_t	temp;

	while (len--)
	{
		temp = value % base;
		value /= base;
		if (temp <= 9)
			str[len] = temp + '0';
		else
			str[len] = temp + 'A' - 10;
	}
}

char			*ft_itoabase_max(intmax_t value, int base)
{
	char		*str;
	size_t		len;
	int			neg;
	intmax_t	temp;

	if (value == 0 || base <= 1)
		return (ft_strdup("0"));
	if (value < 0)
	{
		neg = 1;
		value = -value;
	}
	else
		neg = 0;
	len = 2 + neg;
	temp = value;
	while (temp /= base)
		len++;
	if (!(str = (char*)safe_malloc(len)))
		return (NULL);
	str[--len] = '\0';
	sft_loadchar(str, len, value, base);
	if (neg)
		str[0] = '-';
	return (str);
}
