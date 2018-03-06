/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 14:06:26 by vbondare          #+#    #+#             */
/*   Updated: 2017/01/05 18:55:24 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	correct(const char *str)
{
	if (*str == ' ' || *str == '\a')
		return (0);
	else if (*str == '\b' || *str == '\t')
		return (0);
	else if (*str == '\n' || *str == '\v')
		return (0);
	else if (*str == '\r' || *str == '\f')
		return (0);
	return (1);
}

int			ft_atoi(const char *str)
{
	int		neg;
	int		nb;

	neg = 1;
	nb = 0;
	while (correct(str) == 0)
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str == '0')
		str++;
	while (*str != '\0')
	{
		if ((*str < 48) || (*str > 57))
			return (nb * neg);
		nb = nb * 10 + *str - 48;
		str++;
	}
	return (nb * neg);
}
