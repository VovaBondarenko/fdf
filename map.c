/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 16:46:17 by vbondare          #+#    #+#             */
/*   Updated: 2017/10/16 17:27:50 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		move_fdf(t_mlx *mlx, int keycode)
{
	t_map	*map;

	map = mlx->map;
	mlx_clear_window(mlx->mlx, mlx->win);
	if (keycode == 124)
		map->i_move_x += 1 * POINT_DISTANCE;
	if (keycode == 123)
		map->i_move_x += -1 * POINT_DISTANCE;
	if (keycode == 125)
		map->i_move_y += 1 * POINT_DISTANCE;
	if (keycode == 126)
		map->i_move_y += -1 * POINT_DISTANCE;
	draw(mlx);
}

int			clean_map(t_map **map)
{
	ft_memdel((void **)&map);
	return (0);
}

void		get_win_size(t_map *map)
{
	int		def_size;
	int		mult;
	int		max_count;
	int		min_count;

	mult = map->width * map->height;
	def_size = 400;
	max_count = 100;
	min_count = 0;
	if (mult <= 1300)
	{
		while (!(min_count >= mult) && mult <= max_count)
		{
			if (def_size > 400)
				def_size += 100;
			min_count += 100;
			max_count += 100;
		}
		map->img_size = def_size;
	}
	else
		map->img_size = 1300;
}

void		get_map_centre(t_map *map)
{
	int		x;
	int		y;

	map->move_x = (map->points[((map->height - 1) * map->width
				+ map->width - 1)]->x - map->points[0]->x) / 2;
	map->move_y = (map->points[((map->height - 1) * map->width
				+ map->width - 1)]->y - map->points[0]->y) / 2;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->points[y * map->width + x]->x +=
				((map->img_size) / 2) - map->move_x;
			map->points[y * map->width + x]->y +=
				((map->img_size) / 2) - map->move_y;
			x++;
		}
		y++;
	}
}

t_map		*get_map(int width, int height)
{
	t_map	*map;

	map = ft_memalloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->width = width;
	map->height = height;
	map->min = 0;
	map->max = 0;
	map->i_move_x = 0;
	map->i_move_y = 0;
	map->points = ft_memalloc(sizeof(t_point*) * width * height);
	if (map->points == NULL)
	{
		ft_memdel((void **)&map);
		return (NULL);
	}
	return (map);
}
