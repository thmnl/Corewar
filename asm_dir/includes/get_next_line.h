/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:56:57 by brocher           #+#    #+#             */
/*   Updated: 2018/04/09 13:50:26 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

# define BUFF_SIZE 4096

typedef struct			s_lstline
{
	char				*str;
	int					fd;
	struct s_lstline	*next;
}						t_lstline;

int						get_next_line(const int fd, char **line);

#endif
