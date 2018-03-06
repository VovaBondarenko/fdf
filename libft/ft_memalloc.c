/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 14:20:17 by vbondare          #+#    #+#             */
/*   Updated: 2017/01/05 15:26:00 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*mem;
	size_t			i;

	mem = (unsigned char *)malloc(size * sizeof(*mem));
	if (!mem)
		return (NULL);
	i = 0;
	while (i < size)
	{
		mem[i++] = 0;
	}
	return ((void *)mem);
}
