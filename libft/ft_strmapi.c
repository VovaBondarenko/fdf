/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 15:13:38 by vbondare          #+#    #+#             */
/*   Updated: 2017/01/03 17:40:50 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	index;
	char			*new;

	if (!s)
		return (NULL);
	new = (char*)malloc((ft_strlen(s) + 1) * sizeof(*s));
	if (!new)
		return (NULL);
	index = 0;
	while (s[index])
	{
		new[index] = f(index, s[index]);
		index++;
	}
	new[index] = '\0';
	return (new);
}
