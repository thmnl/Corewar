/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putescape_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:35:01 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:35:04 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putescape_fd(char c, int fd)
{
	if (c == 'a')
		write(fd, "\a", 1);
	else if (c == 'b')
		write(fd, "\b", 1);
	else if (c == 'f')
		write(fd, "\f", 1);
	else if (c == 'n')
		write(fd, "\n", 1);
	else if (c == 'r')
		write(fd, "\r", 1);
	else if (c == 't')
		write(fd, "\t", 1);
	else if (c == 'v')
		write(fd, "\v", 1);
	else if (c == '\\')
		write(fd, "\\", 1);
}
