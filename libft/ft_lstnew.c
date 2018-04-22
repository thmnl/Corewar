/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:28:34 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:28:37 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*lp;

	if (!(lp = (t_list*)safe_malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(lp->content = ft_memalloc(content_size)))
			return (NULL);
		ft_memcpy(lp->content, content, content_size);
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
