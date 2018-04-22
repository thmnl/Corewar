/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:27:09 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:27:10 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*todel;
	t_list	*next;

	next = *alst;
	while (next)
	{
		todel = next;
		next = next->next;
		ft_lstdelone(&todel, del);
		free(todel);
	}
	*alst = NULL;
}
