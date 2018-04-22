/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:15:56 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:15:57 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	sft_check_errors(char *str, int *err)
{
	int i;

	*err = 0;
	str++;
	if (ft_strlen(str) > 11)
		*err = 1;
	if (str[0] != '-' && str[0] != '+' && !ft_isdigit(str[0]))
		*err = 1;
	if ((str[0] == '-' || str[0] == '+') && (!str[1] || str[1] == ' '))
		*err = 1;
	i = 1;
	while (str[i])
	{
		if (str[i] == ' ')
			break ;
		if (!ft_isdigit(str[i++]))
			*err = 1;
	}
}

int			ft_atoi_safe(char *str, int *err)
{
	intmax_t	result;
	int			sign;

	sft_check_errors(str, err);
	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\v' ||
			*str == '\n' || *str == '\f' || *str == '\r')
	{
		str++;
	}
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += (*str) - '0';
		str++;
	}
	result *= sign;
	if (result > INT_MAX || result < INT_MIN)
		*err = 1;
	return (result);
}
