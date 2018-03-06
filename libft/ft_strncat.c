/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:54:12 by vbondare          #+#    #+#             */
/*   Updated: 2017/01/05 13:54:15 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncat(char *dst, const char *app, size_t n)
{
	int index_d;
	int index_s;

	index_d = 0;
	index_s = 0;
	while (dst[index_d] != '\0')
		index_d++;
	while (app[index_s] != '\0' && n != 0)
	{
		dst[index_d] = app[index_s];
		index_s++;
		index_d++;
		n--;
	}
	dst[index_d] = '\0';
	return (dst);
}
