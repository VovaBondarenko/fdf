/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 16:48:08 by vbondare          #+#    #+#             */
/*   Updated: 2017/10/16 17:59:17 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		get_point_color(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->points[y * map->width + x]->color = get_color(map,
					map->points[y * map->width + x]->z);
			x++;
		}
		y++;
	}
}

int			get_color(t_map *map, double z)
{
	double	h;
	int		color;
	double	per;

	color = 0xffffff;
	h = (double)(map->max - map->min);
	per = (z / POINT_DISTANCE) / h;
	if (per >= 0.0 && per < 0.4)
		color = 0x00ff00;
	if (per <= 0.6 && per >= 0.4)
		color = 0x996633;
	if (per < 0.0 || per > 0.6)
		color = 0xffffff;
	return (color);
}
