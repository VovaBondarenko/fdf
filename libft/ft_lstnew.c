/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:19:09 by vbondare          #+#    #+#             */
/*   Updated: 2017/01/05 13:56:45 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *res;

	res = (t_list*)malloc(sizeof(*res));
	if (res == NULL)
		return (NULL);
	if (content == NULL)
	{
		res->content = NULL;
		res->content_size = 0;
	}
	else
	{
		res->content_size = content_size;
		res->content = malloc(content_size);
		res->content = ft_memcpy(res->content, content, content_size);
	}
	res->next = NULL;
	return (res);
}
