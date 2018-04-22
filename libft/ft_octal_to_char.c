/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal_to_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:32:19 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:32:20 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_octal_to_char(char *str, int max_len)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	while (ft_isoctal(str[i]) && i < max_len)
		c = c * 8 + str[i++] - '0';
	return (c);
}
