/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:50:08 by vbondare          #+#    #+#             */
/*   Updated: 2017/01/05 16:27:53 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*res;

	res = NULL;
	while (*str != '\0')
	{
		if (*str == ch)
			res = (char*)str;
		str++;
	}
	if (*str == '\0' && ch == '\0')
		return ((char*)str);
	if (res == '\0')
		return (NULL);
	else
		return (res);
}
