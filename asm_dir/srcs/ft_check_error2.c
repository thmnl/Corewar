/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:04:58 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/16 14:25:25 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_champ	*ft_name(t_champ *f, char *s, int l)
{
	int		i;

	i = 0;
	while (*s && (*s == ' ' || *s == '\t'))
		s++;
	if (!s)
		return (ft_token_error("ENDLINE", f, l));
	if (f->name)
		return (ft_token_error("Too many names", f, l));
	if (s[0] != 34)
		return (ft_lexic_error(s, f, l, 0));
	i++;
	while (s[i] != 34 && s[i])
		i++;
	if (s[i] == 34 && s[i + 1] == '\0')
	{
		s[i] = '\0';
		if (f->name)
			ft_strdel(&f->name);
		f->name = ft_strdup(s + 1);
	}
	else
		return (ft_lexic_error(s, f, l, i + 1));
	return (f);
}

static t_champ	*ft_comment(t_champ *f, char *s, int l)
{
	int		i;

	i = 0;
	while (*s && (*s == ' ' || *s == '\t'))
		s++;
	if (!s)
		return (ft_token_error("ENDLINE", f, l));
	if (f->comment)
		return (ft_token_error("Too many comments", f, l));
	if (s[0] != 34)
		return (ft_lexic_error(s, f, l, 0));
	i++;
	while (s[i] != 34 && s[i])
		i++;
	if (s[i] == 34 && s[i + 1] == '\0')
	{
		s[i] = '\0';
		if (f->comment)
			ft_strdel(&f->comment);
		f->comment = ft_strdup(s + 1);
	}
	else
		return (ft_lexic_error(s, f, l, i + 1));
	return (f);
}

static char		*ft_find_cmd(char *s)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strdup(s);
	while (s[i] && s[i] != ' ' && s[i] != '\t')
		i++;
	tmp[i] = '\0';
	return (tmp);
}

t_champ			*ft_check_error3(t_champ *f)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < 2 && f->tchamp[i])
	{
		tmp = ft_find_cmd(f->tchamp[i]);
		if (!ft_strcmp(tmp, COMMENT_CMD_STRING))
			f = ft_comment(f, f->tchamp[i] + ft_strlen(COMMENT_CMD_STRING), i);
		else if (!ft_strcmp(tmp, NAME_CMD_STRING))
			f = ft_name(f, f->tchamp[i] + ft_strlen(NAME_CMD_STRING), i);
		else
			f = ft_token_error("Bad or no comment/name", f, i);
		i++;
		ft_strdel(&tmp);
	}
	if (i != 2)
		f = ft_token_error("END \"(null)\"", f, i);
	return (ft_check_error4(f));
}
