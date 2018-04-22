/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoalong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:25:17 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:25:18 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		sft_isneg(int long *n, int *neg)
{
	if (*n < 0)
	{
		*n *= -1;
		*neg = 1;
	}
}

char			*ft_itoalong(int long n)
{
	char	*str;
	int		len;
	int		nc;
	int		neg;

	len = 2;
	neg = 0;
	sft_isneg(&n, &neg);
	nc = n;
	while (nc /= 10)
		len++;
	len += neg;
	if (!(str = (char*)safe_malloc(len)))
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
