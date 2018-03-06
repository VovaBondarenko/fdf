/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 16:51:16 by vbondare          #+#    #+#             */
/*   Updated: 2017/01/05 18:20:31 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int	check(char s)
{
	if (s == ' ' || s == '\n' || s == '\t')
		return (1);
	if (s == '\r' || s == '\v' || s == '\f')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		i;
	char	*new;

	if (!s)
		return (NULL);
	start = -1;
	end = ft_strlen(s);
	while (check(s[++start]) && start < end)
		;
	while (check(s[--end]) && end >= 0)
		;
	if (end < start)
		return ("");
	new = (char *)malloc((end - start + 2) * sizeof(*new));
	if (!new)
		return (NULL);
	i = 0;
	while (start <= end)
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}
