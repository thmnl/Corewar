/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_ref.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:28:50 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:28:51 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew_ref(void const *content, size_t content_size)
{
	t_list		*lp;

	if (!(lp = (t_list*)safe_malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		lp->content = (void*)content;
		lp->content_size = content_size;
	}
	else
	{
		lp->content = NULL;
		lp->content_size = 0;
	}
	lp->next = NULL;
	return (lp);
}
