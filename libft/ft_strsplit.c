/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brocher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:54:31 by brocher           #+#    #+#             */
/*   Updated: 2018/03/16 10:54:32 by brocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*sft_spllitdup(const char *src, char c)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i] && src[i] != c)
		i++;
	dest = (char*)safe_malloc(i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int		sft_count_lines(const char *str, char c)
{
	int i;
	int line_count;
	int in_word;

	in_word = 0;
	i = 0;
	line_count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			if (in_word == 0)
				line_count++;
			in_word = 1;
		}
		else
			in_word = 0;
		i++;
	}
	return (line_count);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i[3];
	char	**result;

	if (!s)
		return (NULL);
	i[0] = 0;
	i[2] = 0;
	i[1] = sft_count_lines(s, c);
	if (!(result = malloc(sizeof(char*) * i[1] + sizeof(char*))))
		return (NULL);
	i[1] = 0;
	while (s[i[0]])
	{
		if (s[i[0]] != c)
		{
			if (i[2] == 0)
				result[i[1]++] = sft_spllitdup(s + i[0], c);
			i[2] = 1;
		}
		else
			i[2] = 0;
		i[0]++;
	}
	result[i[1]] = NULL;
	return (result);
}
