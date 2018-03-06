/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:14:11 by vbondare          #+#    #+#             */
/*   Updated: 2017/01/05 13:17:53 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
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
		index++;
	}
	return (dst);
}
