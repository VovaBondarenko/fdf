/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 18:26:40 by vbondare          #+#    #+#             */
/*   Updated: 2017/01/03 18:26:01 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	sign;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		ft_putchar_fd('-', fd);
	}
	if (n >= -9 && n <= 9)
		ft_putchar_fd(48 + sign * n, fd);
	else
	{
		ft_putnbr_fd(n / 10 * sign, fd);
		ft_putnbr_fd(n % 10 * sign, fd);
	}
}
