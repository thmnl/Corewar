/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:59:51 by allallem          #+#    #+#             */
/*   Updated: 2018/04/12 12:59:10 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_pfspe	*ft_init_struct(t_pfspe *point)
{
	ft_init_pfspe(point);
	point->cursor = 0;
	point->i = 0;
	point->value = 0;
	return (point);
}

static int		ft_check_denom(const char *s, t_pfspe *p)
{
	int k;

	if ((k = ft_printf_spe(s, p)) == -1)
		return (0);
	return (k);
}

static void		ft_startpf(const char *str, t_pfspe *p)
{
	while (str[p->i])
	{
		if (str[p->i] == '%' && str[p->i + 1] == '\0')
			break ;
		if (str[p->i] == '%')
		{
			p->i++;
			if ((p->i = p->i + ft_check_denom(str + p->i, p)))
			{
				p->i++;
				if (str[p->i - 1] == '\0')
					break ;
			}
			else
				ft_check_buffer(p, str[p->i]);
		}
		else
		{
			ft_check_buffer(p, str[p->i]);
			p->i++;
		}
	}
}

int				ft_dprintf(int fd, const char *str, ...)
{
	va_list ap;
	t_pfspe st;
	t_pfspe *p;

	p = &st;
	ft_init_struct(p);
	p->fd = fd;
	va_start(p->ap, str);
	ft_startpf(str, p);
	ft_pull_all(p);
	va_end(ap);
	return (p->value);
}
