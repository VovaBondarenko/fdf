/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 16:47:33 by vbondare          #+#    #+#             */
/*   Updated: 2017/10/16 17:41:56 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			get_map_width(char *str)
{
	int		width;
	int		index;
	int		word;

	word = 0;
	width = 0;
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] != ' ')
		{
			if (word == 0)
			{
				width++;
				word = 1;
			}
		}
		else
			word = 0;
		index++;
	}
	return (width);
}

int			get_map_heigth(t_list *lst)
{
	int		index;

	index = 0;
	if (lst)
		index++;
	while (lst->next)
	{
		lst = lst->next;
		index++;
	}
	return (index);
}

int			get_counts(char *line)
{
	int		index;
	int		count;
	char	*split;

	index = 0;
	count = 0;
	while (line[index] != '\0')
		index++;
	return (index);
}

void		list_reverse(t_list **lst)
{
	t_list	*prev;
	t_list	*next;
	t_list	*current;

	current = *lst;
	prev = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*lst = prev;
}
