/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:42:42 by vbondare          #+#    #+#             */
/*   Updated: 2017/01/05 16:46:35 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_print_char_list(t_char *lst)
{
	if (lst)
	{
		while (lst)
		{
			ft_putstr(lst->content);
			lst = lst->next;
		}
	}
	return ;
}
