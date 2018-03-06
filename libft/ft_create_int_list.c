/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_int_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:41:10 by vbondare          #+#    #+#             */
/*   Updated: 2017/01/05 17:23:16 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_create_int_list(t_int **alst, t_int *new)
{
	if (new == NULL)
		return ;
	(*alst)->next = *alst;
	*alst = new;
}
