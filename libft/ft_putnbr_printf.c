/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 20:40:44 by allallem          #+#    #+#             */
/*   Updated: 2018/01/26 17:12:59 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_printf(long long int n, t_pfspe *point)
{
	if (n < 0)
	{
		ft_check_buffer(point, '-');
		n = n * (-1);
	}
	(n > 9) ? ft_putnbr_printf(n / 10, point) : 0;
	ft_check_buffer(point, (n % 10) + 48);
}
