/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_char_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:34:48 by vbondare          #+#    #+#             */
/*   Updated: 2017/01/05 17:19:43 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_create_char_list(t_char **alst, t_char *new)
{
	if (new == NULL)
		return ;
	(*alst)->next = *alst;
	*alst = new;
}
