/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_argv_options_extras.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 12:56:23 by brocher           #+#    #+#             */
/*   Updated: 2018/04/09 12:56:25 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_struct.h"
#include "vm_proto.h"
#include "errors.h"
#include "libft.h"

static int	sft_check_int(char *str)
{
	int			i;
	intmax_t	value;

	i = 0;
	if (str[i] == '-')
		i++;
	if (!str[i])
		error("\'-\' is not an integer", NULL);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			error("Non-digit character in integer", str);
		i++;
	}
	if (ft_strlen(str) > 11)
		error("Integer is too large", str);
	value = ft_atoi_max(str);
	if (value > INT_MAX || value < INT_MIN)
		error("argument must fit inside an int", str);
	return ((int)value);
}

static char	sft_check_line(char *str, t_options *options)
{
	char ret;

	ret = '\0';
	if (ft_charcount(str, 'n') && ft_charcount(str, 'd'))
		error("can not mix -d and -n options", NULL);
	if (!(*str))
		error(" \'-\' is not a valid option", NULL);
	if (ft_strequ(str, "dump"))
	{
		options->dump += 1;
		ret = 'd';
	}
	else
		ret = lao_switch(str, options);
	if (options->dump > 1)
		error("multiple dump options", NULL);
	return (ret);
}

static char	inner_loop2(char *line, t_options *opt, char mode, int *p_nbr)
{
	if (mode == 'n')
	{
		*p_nbr = sft_check_int(line);
		if (*p_nbr == 0)
			error("champs can not be given an id of 0", NULL);
		mode = '\0';
	}
	else if (mode == 'b')
	{
		opt->debug_nbr = sft_check_int(line);
		mode = '\0';
	}
	else if (mode == 's')
	{
		opt->save_nbr = sft_check_int(line);
		mode = '\0';
	}
	return (mode);
}

char		lao_inner_loop(char *line, t_options *opt, char mode, int *p_nbr)
{
	if (!mode)
	{
		if (line[0] == '-')
			mode = sft_check_line(line + 1, opt);
		else
		{
			options_add_player(line, *p_nbr, opt);
			*p_nbr = 0;
		}
	}
	else if (mode == 'd')
	{
		opt->dump_cycles = sft_check_int(line);
		mode = '\0';
	}
	else
		mode = inner_loop2(line, opt, mode, p_nbr);
	return (mode);
}
