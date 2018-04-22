/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:28:18 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:28:19 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	stft_lstaddend(t_list *start, t_list *new)
{
	if (!start)
		return ;
	while (start->next)
		start = start->next;
	start->next = new;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *temp;

	if (!f)
		return (NULL);
	if (lst)
	{
		new = f(lst);
		if (!new)
			return (NULL);
		lst = lst->next;
	}
	else
		return (NULL);
	while (lst)
	{
		temp = f(lst);
		if (!temp)
			return (NULL);
		stft_lstaddend(new, temp);
		lst = lst->next;
	}
	return (new);
}
