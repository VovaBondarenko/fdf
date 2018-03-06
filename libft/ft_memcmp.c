/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:19:57 by vbondare          #+#    #+#             */
/*   Updated: 2017/01/05 14:09:29 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	const unsigned char			*m1;
	const unsigned char			*m2;
	int							res;

	m1 = (const unsigned char*)arr1;
	m2 = (const unsigned char*)arr2;
	while (n != 0)
	{
		if (*m1 != *m2)
		{
			res = *m1 - *m2;
			return (res);
		}
		m1++;
		m2++;
		n--;
	}
	return (0);
}
