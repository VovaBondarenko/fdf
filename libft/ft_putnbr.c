/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 17:44:30 by vbondare          #+#    #+#             */
/*   Updated: 2017/01/05 13:55:08 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int sign;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		ft_putchar('-');
	}
	if (n >= -9 && n <= 9)
		ft_putchar(48 + sign * n);
	else
	{
		ft_putnbr(n / 10 * sign);
		ft_putnbr(n % 10 * sign);
	}
}
