/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrpad_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:43:26 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:43:27 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrpad_fd(char const *s, int nb, char c, int fd)
{
	char	buffer[nb];
	int		i;

	if (nb < 0)
		return ;
	if (!s)
		return ;
	i = ft_strlen(s);
	ft_strcpy(buffer, s);
	while (i < nb)
		buffer[i++] = c;
	write(fd, buffer, i);
}
