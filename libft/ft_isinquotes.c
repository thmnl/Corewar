/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinquotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:22:01 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:22:02 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isinquotes(char *str, int pos)
{
	int		i;
	int		inquotes;
	char	quote_char;

	i = 0;
	inquotes = 0;
	while (i != pos)
	{
		if ((str[i] == '\'' || str[i] == '\"'))
		{
			if (inquotes)
			{
				if (str[i] == quote_char)
					inquotes = 0;
			}
			else
			{
				quote_char = str[i];
				inquotes = 1;
			}
		}
		i++;
	}
	return (inquotes);
}
