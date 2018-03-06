/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 16:22:18 by vbondare          #+#    #+#             */
/*   Updated: 2017/01/05 16:24:38 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		index;

	if (!s)
		return (NULL);
	res = (char*)malloc((len + 1) * sizeof(*res));
	if (!res)
		return (NULL);
	index = 0;
	while (len != 0)
	{
		res[index] = s[start];
		index++;
		start++;
		len--;
	}
	res[index] = '\0';
	return (res);
}
