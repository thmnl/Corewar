/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strhas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:49:38 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:49:39 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strhas(char *str, char *characters)
{
	while (*str)
	{
		if (ft_strchr(characters, *str))
			return (1);
		str++;
	}
	return (0);
}
