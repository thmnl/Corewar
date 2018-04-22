/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:56:42 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:56:44 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_lstline	*sft_alst(int fd, t_lstline *head)
{
	t_lstline	*new;

	if (!(new = (t_lstline*)safe_malloc(sizeof(t_lstline))))
		return (NULL);
	new->next = NULL;
	new->str = NULL;
	new->fd = fd;
	if (head)
	{
		while (head->next)
			head = head->next;
		head->next = new;
	}
	return (new);
}

static t_lstline	*sft_init(int fd, t_lstline *head, int *ret, int *had_line)
{
	t_lstline	*temp;

	*ret = 1;
	*had_line = 0;
	temp = head;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	return (sft_alst(fd, head));
}

static char			*sft_add_buffer(char *dest, char *src)
{
	char	*newstr;

	if (!(newstr = ft_strjoin(dest, src)))
		return (NULL);
	free(dest);
	ft_strclr(src);
	return (newstr);
}

static char			*sft_extract_line(char **buffer)
{
	char	*temp;
	char	*temp2;
	int		had_line;

	had_line = 0;
	temp = ft_strchr(*buffer, '\n');
	if (temp)
	{
		*temp = '\0';
		had_line = 1;
	}
	if (!(temp = ft_strnew(ft_strlen(*buffer))))
		return (NULL);
	temp = ft_strcpy(temp, *buffer);
	if (had_line)
	{
		if (!(temp2 = ft_strdup((*buffer) + ft_strlen(temp) + 1)))
			return (NULL);
	}
	else
		temp2 = NULL;
	free(*buffer);
	*buffer = temp2;
	return (temp);
}

int					get_next_line(const int fd, char **line)
{
	static t_lstline	*head = NULL;
	char				temp_buff[BUFF_SIZE + 1];
	int					ret;
	int					had_line;
	t_lstline			*current;

	if (fd < 0 || !line || (!head && !(head = sft_alst(fd, head))))
		return (-1);
	if (!(current = sft_init(fd, head, &ret, &had_line)))
		return (-1);
	while (!had_line && ret && !ft_strchr(current->str, '\n'))
	{
		if ((ret = read(fd, temp_buff, BUFF_SIZE)) < 0)
			return (-1);
		temp_buff[ret] = '\0';
		if (ft_strchr(temp_buff, '\n'))
			had_line = 1;
		if (!current->str && !(current->str = ft_strnew(0)))
			return (-1);
		if (!(current->str = sft_add_buffer(current->str, temp_buff)))
			return (-1);
	}
	if (!(*line = sft_extract_line(&current->str)))
		return (-1);
	return ((!ft_strlen(*line) && !current->str) && !ret ? 0 : 1);
}
