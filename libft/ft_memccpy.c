/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:32:14 by vbondare          #+#    #+#             */
/*   Updated: 2017/01/05 14:48:31 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*dst_c;
	char	*src_c;
	size_t	index;

	index = 0;
	dst_c = (char*)dst;
	src_c = (char*)src;
	while (index < n)
	{
		dst_c[index] = src_c[index];
		if (src_c[index] == c)
			return (dst_c + index + 1);
		index++;
	}
	return (NULL);
}
