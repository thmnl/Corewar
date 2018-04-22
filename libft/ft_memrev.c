/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:31:27 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:31:28 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memrev(void *memory, size_t len)
{
	unsigned char	*mem;
	unsigned char	swap;
	size_t			start;
	size_t			end;

	start = 0;
	end = len - 1;
	mem = (unsigned char*)memory;
	while (end > start)
	{
		swap = mem[start];
		mem[start] = mem[end];
		mem[end] = swap;
		end--;
		start++;
	}
}
