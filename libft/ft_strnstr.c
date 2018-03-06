/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:25:28 by vbondare          #+#    #+#             */
/*   Updated: 2017/01/05 18:25:29 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	int i;

	if (!(*lit))
		return ((char *)big);
	while (*big != '\0' && len)
	{
		if (*big == *lit)
		{
			i = 0;
			while (big[i] == lit[i] && i < (int)len && lit[i] != '\0')
				i++;
			if (lit[i] == '\0')
				return ((char *)big);
		}
		big++;
		len--;
	}
	return (NULL);
}
