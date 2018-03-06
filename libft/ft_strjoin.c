/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 16:43:25 by vbondare          #+#    #+#             */
/*   Updated: 2017/01/05 16:31:15 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		index;

	if (!s1 || !s2)
		return (NULL);
	res = (char*)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(*res));
	if (!res)
		return (NULL);
	index = 0;
	while (*s1)
		res[index++] = *s1++;
	while (*s2)
		res[index++] = *s2++;
	res[index] = '\0';
	return (res);
}
