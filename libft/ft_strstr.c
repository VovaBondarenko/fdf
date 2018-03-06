/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 16:11:38 by vbondare          #+#    #+#             */
/*   Updated: 2017/01/05 14:48:08 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	const char	*s1;
	const char	*s2;

	if (ft_strlen(str2) == 0)
		return (char *)(str1);
	while (*str1)
	{
		if (*str1 != *str2)
		{
			str1++;
			continue;
		}
		s1 = str1;
		s2 = str2;
		while (1)
		{
			if (!*s2)
				return (char *)(str1);
			if (*s1++ != *s2++)
				break ;
		}
		str1++;
	}
	return (NULL);
}
