/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 16:47:48 by vbondare          #+#    #+#             */
/*   Updated: 2017/10/16 17:53:20 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		paint(t_mlx *mlx, int x, int y, t_point p1)
{
	mlx_pixel_put(mlx->mlx, mlx->win, x + mlx->map->i_move_x,
			y + mlx->map->i_move_y, p1.color);
}

void		brezenhem_up(t_point p1, t_point p2, t_brez *tmp, t_mlx *mlx)
{
	int		f;

	f = 0;
	while (tmp->x != (int)p2.x || tmp->y != (int)p2.y)
	{
		f += ((int)p2.y - (int)p1.y) * tmp->sign_a;
		if (f > 0)
		{
			f -= ((int)p1.x - (int)p2.x) * tmp->sign_b;
			tmp->y += tmp->sign_a;
		}
		tmp->x -= tmp->sign_b;
		paint(mlx, tmp->x, tmp->y, p1);
	}
}

void		brezenhem_down(t_point p1, t_point p2, t_brez *tmp, t_mlx *mlx)
{
	int		f;

	f = 0;
	while (tmp->x != (int)p2.x || tmp->y != (int)p2.y)
	{
		f += ((int)p1.x - (int)p2.x) * tmp->sign_b;
		if (f > 0)
		{
			f -= ((int)p2.y - (int)p1.y) * tmp->sign_a;
			tmp->x -= tmp->sign_b;
		}
		tmp->y += tmp->sign_a;
		paint(mlx, tmp->x, tmp->y, p1);
	}
}

void		brezenhem(t_point p1, t_point p2, t_mlx *mlx)
{
	t_brez	*tmp;

	tmp = malloc(sizeof(t_brez*));
	tmp->sign_a = ((p2.y - p1.y) < 0) ? -1 : 1;
	tmp->sign_b = ((p1.x - p2.x) < 0) ? -1 : 1;
	tmp->x = (int)p1.x;
	tmp->y = (int)p1.y;
	if (abs((int)p2.y - (int)p1.y) < abs((int)p1.x - (int)p2.x))
		brezenhem_up(p1, p2, tmp, mlx);
	else
		brezenhem_down(p1, p2, tmp, mlx);
}

void		draw(t_mlx *mlx)
{
	int		x;
	int		y;
	t_point	*point;
	t_map	*map;

	map = mlx->map;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x + 1 < map->width)
				brezenhem(*map->points[y * map->width + x],
						*map->points[y * map->width + x + 1], mlx);
			if (y + 1 < map->height)
				brezenhem(*map->points[y * map->width + x],
						*map->points[(y + 1) * map->width + x], mlx);
			x++;
		}
		y++;
	}
}
