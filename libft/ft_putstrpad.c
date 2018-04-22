/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrpad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:43:06 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:43:07 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrpad(char const *s, int nb, char c)
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
	write(1, buffer, i);
}
