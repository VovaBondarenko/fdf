/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:44:33 by vbondare          #+#    #+#             */
/*   Updated: 2017/01/03 17:59:02 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strcat(char *dst, const char *app)
{
	int	index_d;
	int	index_s;

	index_d = 0;
	index_s = 0;
	while (dst[index_d] != '\0')
		index_d++;
	while (app[index_s] != '\0')
	{
		dst[index_d] = app[index_s];
		index_s++;
		index_d++;
	}
	dst[index_d] = '\0';
	return (dst);
}
