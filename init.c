/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 16:46:44 by vbondare          #+#    #+#             */
/*   Updated: 2017/10/16 17:32:36 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx		*init(char *name, t_map *map)
{
	t_mlx	*mlx;

	if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	else
	{
		mlx->mlx = mlx_init();
		mlx->width = map->img_size;
		mlx->height = map->img_size;
		mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, name);
	}
	return (mlx);
}
