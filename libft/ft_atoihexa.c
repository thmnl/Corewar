/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoihexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:16:20 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:16:22 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoihexa(char *str)
{
	int result;

	result = 0;
	while (ft_ishexa(*str))
	{
		result *= 16;
		if (ft_isdigit(*str))
			result += (*str) - '0';
		else if (*str > 91)
			result += (*str) - 'a' + 10;
		else
			result += (*str) - 'A' + 10;
		str++;
	}
	return (result);
}
