/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdtostr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:19:53 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:19:54 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fdtostr(int fd)
{
	char	*result;
	char	*temp;
	char	buffer[LIBFT_BUFF_SIZE + 1];
	int		ret;

	if (fd < 0)
		return (NULL);
	if (!(result = ft_strdup("")))
		return (NULL);
	while ((ret = read(fd, buffer, LIBFT_BUFF_SIZE)) && ret != -1)
	{
		buffer[ret] = '\0';
		if (!(temp = ft_strjoin(result, buffer)))
			return (NULL);
		free(result);
		result = temp;
	}
	return (result);
}
