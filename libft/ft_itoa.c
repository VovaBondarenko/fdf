/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 13:56:39 by vbondare          #+#    #+#             */
/*   Updated: 2017/01/05 18:31:48 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		num_len(int n)
{
	int			len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 1)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void		reverse(char *res, int sign)
{
	char		tmp;
	char		*end;

	end = res + ft_strlen(res);
	if (sign == -1)
		res++;
	if (ft_strlen(res) < 2)
		return ;
	while (res < --end)
	{
		tmp = *res;
		*res = *end;
		*end = tmp;
		++res;
	}
}

char			*ft_itoa(int n)
{
	char		*res;
	int			index;
	int			sign;

	index = 0;
	sign = 1;
	res = (char*)malloc((num_len(n) + 1) * sizeof(*res));
	if (!res)
		return (NULL);
	if (n == 0)
		res[index++] = 0 + '0';
	if (n < 0)
	{
		res[index++] = '-';
		sign = -1;
	}
	while (n != 0)
	{
		res[index++] = ((n % 10) * sign) + '0';
		n /= 10;
	}
	res[index] = '\0';
	reverse(res, sign);
	return (res);
}
