/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 14:35:40 by vbondare          #+#    #+#             */
/*   Updated: 2017/01/05 15:26:37 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tdst;
	unsigned char	*tsrc;
	unsigned		buff;

	tdst = (unsigned char *)dst;
	tsrc = (unsigned char *)src;
	if (dst > src)
	{
		while (len > 0)
		{
			tdst[len - 1] = tsrc[len - 1];
			len--;
		}
	}
	else
		while (len > 0)
		{
			buff = *tsrc;
			*tdst = buff;
			tsrc++;
			tdst++;
			len--;
		}
	return (dst);
}
