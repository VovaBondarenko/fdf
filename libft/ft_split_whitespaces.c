/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:11:00 by vbondare          #+#    #+#             */
/*   Updated: 2017/01/05 18:30:35 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		is_space(char *str, int i)
{
	if (str[i + 1] == '\n' || str[i + 1] == '\0')
		return (1);
	return (0);
}

static void		allocate_memory(char *str, char **arr, int i, int j)
{
	int n;

	n = 0;
	while (str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] != '\n')
		{
			j++;
			if (is_space(str, i))
			{
				arr[n] = (char *)malloc(sizeof(char) * (j + 1));
				j = 0;
				n++;
			}
		}
		i++;
	}
}

static char		**allocate_word(char *str, char **arr, int i, int j)
{
	int			n;

	n = 0;
	while (str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] != '\n')
		{
			arr[n][j] = str[i];
			j++;
			if (is_space(str, i))
			{
				arr[n][j] = '\0';
				j = 0;
				n++;
			}
		}
		i++;
	}
	arr[n] = 0;
	return (arr);
}

char			**ft_split_whitespaces(char *str)
{
	int			i;
	int			j;
	int			words;
	char		**arr;

	i = 0;
	j = 0;
	words = 0;
	while (str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] != '\n')
			if (is_space(str, i))
				words++;
		i++;
	}
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	i = 0;
	allocate_memory(str, arr, i, j);
	arr = allocate_word(str, arr, i, j);
	return (arr);
}
