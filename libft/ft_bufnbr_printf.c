/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 20:27:23 by allallem          #+#    #+#             */
/*   Updated: 2018/01/26 16:47:43 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_bufnbr_printf(long long int n, t_pfspe *point)
{
	if (n == 0 && point->plus > 0 && point->size_content == 1)
		return ;
	(n > 9 || n < -9) ? ft_bufnbr_printf(n / 10, point) : 0;
	(n > 0) ? ft_check_buffer(point, (n % 10) + 48) :
		ft_check_buffer(point, (-1 * (n % 10) + 48));
}
