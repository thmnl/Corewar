/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:26:38 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:26:39 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*nav;

	nav = *alst;
	if (!nav)
	{
		*alst = new;
		return ;
	}
	while (nav->next)
		nav = nav->next;
	nav->next = new;
}
