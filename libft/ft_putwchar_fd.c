/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:44:09 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:44:10 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putwchar_fd(wchar_t wc, int fd)
{
	if (wc <= 0x7f)
		ft_putchar_fd(wc, fd);
	else if (wc <= 0x7ff)
	{
		ft_putchar_fd((wc >> 6) + 0xc0, fd);
		ft_putchar_fd((wc & 0x3f) + 0x80, fd);
		return (2);
	}
	else if (wc <= 0xffff)
	{
		ft_putchar_fd((wc >> 12) + 0xe0, fd);
		ft_putchar_fd(((wc >> 6) & 0x3f) + 0x80, fd);
		ft_putchar_fd((wc & 0x3f) + 0x80, fd);
		return (3);
	}
	else if (wc <= 0x10ffff)
	{
		ft_putchar_fd((wc >> 18) + 0xf0, fd);
		ft_putchar_fd(((wc >> 12) & 0x3f) + 0x80, fd);
		ft_putchar_fd(((wc >> 6) & 0x3f) + 0x80, fd);
		ft_putchar_fd((wc & 0x3f) + 0x80, fd);
		return (4);
	}
	return (1);
}
