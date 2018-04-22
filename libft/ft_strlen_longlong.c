/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_longlong.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 09:46:47 by allallem          #+#    #+#             */
/*   Updated: 2018/01/26 17:13:42 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

long long int		ft_strlen_longlong(char *str)
{
	long long int n;

	n = 0;
	if (str == NULL)
		return (0);
	while (str[n])
		n++;
	return (n);
}
