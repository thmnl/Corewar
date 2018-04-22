/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 12:54:23 by brocher           #+#    #+#             */
/*   Updated: 2018/04/20 15:33:36 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

void	error(char *errmsg, char *additional)
{
	ft_putstr_fd("corewar: error: ", 2);
	ft_putstr_fd(errmsg, 2);
	if (additional)
	{
		ft_putchar_fd(' ', 2);
		ft_putstr_fd(additional, 2);
	}
	ft_putchar_fd('\n', 2);
	exit(EXIT_FAILURE);
}

void	*safe_malloc(size_t bytes)
{
	void	*result;

	result = malloc(bytes);
	if (!result)
		error("out of memory", NULL);
	return (result);
}

void	usage(void)
{
	ft_printf("%yusage: corewar [options] [ (-n int) champions.cor]\n", 2);
	ft_printf("-d --dump [int] dump memory after int cycles\n");
	ft_printf("-g graphic ncurse rendering mode\n");
	ft_printf("-n [int] specify player number\n");
	ft_printf("-s [int] save output mode\n");
	ft_printf("-b [int] print cycle[int]\n");
	ft_printf("-m mute\n");
	exit(EXIT_FAILURE);
}
