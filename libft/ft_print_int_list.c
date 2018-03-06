/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:45:54 by vbondare          #+#    #+#             */
/*   Updated: 2017/01/05 17:17:23 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_print_int_list(t_int *lst)
{
	if (lst)
	{
		while (lst)
		{
			ft_putnbr(*lst->content);
			lst = lst->next;
		}
	}
	return ;
}
