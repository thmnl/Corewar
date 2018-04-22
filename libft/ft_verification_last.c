/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verification_last.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:46:42 by allallem          #+#    #+#             */
/*   Updated: 2018/01/22 17:37:08 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_verification_last(char const *str, t_pfspe *point)
{
	int i;

	i = 0;
	while (str[i] == 'z' || str[i] == 'j')
		i++;
	if (i > 1 || (str[i] == 'h' && i > 0) || (str[i] == 'l' && i > 0))
		return (-1);
	while (str[i] == 'h')
		i++;
	while (str[i] == 'l')
		i++;
	if (i > 2)
		return (-1);
	point->result += i;
	return (i);
}
