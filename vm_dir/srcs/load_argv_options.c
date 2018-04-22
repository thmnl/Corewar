/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_argv_options.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <brocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 12:56:13 by brocher           #+#    #+#             */
/*   Updated: 2018/04/19 14:14:32 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_struct.h"
#include "vm_proto.h"
#include "errors.h"

static int		sft_switch2(char *str, int i, t_options *options, int ret)
{
	if (str[i] == 'b')
	{
		options->debug = 1;
		ret = 'b';
	}
	else if (str[i] == 'n')
		ret = 'n';
	else if (str[i] == 's')
	{
		ret = 's';
		options->save = 1;
	}
	else
		error("Invalid option", str);
	return (ret);
}

char			lao_switch(char *str, t_options *options)
{
	int		i;
	char	ret;

	ret = '\0';
	i = 0;
	while (str[i])
	{
		if (str[i] == 'd')
		{
			options->dump += 1;
			ret = 'd';
		}
		else if (str[i] == 'g')
		{
			options->graphic = 1;
			options->mute = 1;
		}
		else if (str[i] == 'm')
			options->mute = 1;
		else
			ret = sft_switch2(str, i, options, ret);
		i++;
	}
	return (ret);
}

void			load_options(int argc, char **argv, t_options *options)
{
	int		i;
	int		p_nbr;
	char	mode;

	p_nbr = 0;
	options->p_list = NULL;
	mode = '\0';
	i = 1;
	while (i < argc)
	{
		mode = lao_inner_loop(argv[i], options, mode, &p_nbr);
		i++;
	}
	if (mode)
		error("expected integer options", NULL);
	options->nbr_champs = ft_lstcount(options->p_list);
	if (!options->p_list)
		error("no champions", NULL);
	if (ft_lstcount(options->p_list) > MAX_PLAYERS)
		error("Too many players", NULL);
}
