/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:44:41 by vbondare          #+#    #+#             */
/*   Updated: 2017/01/05 14:47:30 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*res;
	int				index;

	index = 0;
	if (n > 0)
	{
		res = (unsigned char*)malloc(sizeof(unsigned char*) * (n + 1));
		res = (unsigned char*)str;
	}
	while (n != 0)
	{
		res[index] = c;
		index++;
		n--;
	}
	return (str);
}
