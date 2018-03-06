/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 15:01:58 by vbondare          #+#    #+#             */
/*   Updated: 2017/01/05 14:31:50 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*new;
	unsigned int	index;

	if (!s)
		return (NULL);
	new = (char*)malloc((ft_strlen(s) + 1) * sizeof(*new));
	if (!new)
		return (NULL);
	index = 0;
	while (s[index])
	{
		new[index] = f(s[index]);
		index++;
	}
	new[index] = '\0';
	return (new);
}
