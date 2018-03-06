/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 15:19:28 by vbondare          #+#    #+#             */
/*   Updated: 2017/01/05 14:05:30 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	t1;
	unsigned char	t2;
	int				index;

	index = 0;
	while (s1[index] == s2[index] && s1[index] && s2[index])
		index++;
	t1 = (unsigned char)s1[index];
	t2 = (unsigned char)s2[index];
	return (t1 - t2);
}
