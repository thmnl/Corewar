/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:36:04 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:36:06 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int		ft_putfile(char *filename)
{
	int		fd;
	int		ret;
	char	buffer[BUFF_SIZE + 1];

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		write(1, &buffer, ret);
	}
	if (close(fd) == -1)
		return (-1);
	return (0);
}
