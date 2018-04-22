/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoaabs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmenard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 11:02:29 by dmenard           #+#    #+#             */
/*   Updated: 2017/01/05 11:05:36 by dmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		sft_isneg(int *n)
{
	if (*n < 0)
		*n *= -1;
}

char			*ft_itoaabs(int n)
{
	char	*str;
	int		len;
	int		nc;

	len = 2;
	if (n == -2147483648)
		return (ft_strdup("2147483648"));
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
