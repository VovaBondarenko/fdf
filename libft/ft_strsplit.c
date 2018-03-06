/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 17:49:25 by vbondare          #+#    #+#             */
/*   Updated: 2017/01/05 18:56:37 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		is_words(char const *s, char dlm)
{
	int			words;
	int			index;

	index = 0;
	words = 0;
	while (s[index])
	{
		if (s[index] != dlm && (s[index + 1] == 0 || s[index + 1] == dlm))
			words++;
		if (s[index] == dlm)
		{
			index++;
			continue;
		}
		index++;
	}
	return (words);
}

static int		len_word(char const *s, char c)
{
	int			len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len + 1);
}

static	void	skip(char const **s, char c)
{
	while (**s == c && **s)
		(*s)++;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		index_w;
	int		index;

	if (!s)
		return (NULL);
	index_w = 0;
	res = (char**)malloc((is_words(s, c) + 1) * sizeof(*res));
	if (!res)
		return (NULL);
	while (*s)
	{
		skip(&s, c);
		if (!*s)
			break ;
		res[index_w] = (char*)malloc((len_word(s, c) + 1) * sizeof(char*));
		if (!res[index_w])
			return (NULL);
		index = 0;
		while (*s != c && *s)
			res[index_w][index++] = *s++;
		res[index_w++][index] = '\0';
	}
	res[index_w] = NULL;
	return (res);
}
