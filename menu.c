/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 16:45:58 by vbondare          #+#    #+#             */
/*   Updated: 2017/10/16 17:21:31 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		zoom(t_mlx *mlx, int keycode)
{
	int		x;
	int		y;
	double	coef;
	t_map	*map;

	map = mlx->map;
	mlx_clear_window(mlx->mlx, mlx->win);
	if (keycode == 69)
		coef = 1.1;
	else
		coef = 0.9;
	y = 0;
	while (y < mlx->map->height)
	{
		x = 0;
		while (x < mlx->map->width)
		{
			map->points[y * mlx->map->width + x]->x *= coef;
			map->points[y * mlx->map->width + x]->y *= coef;
			x++;
		}
		y++;
	}
	draw(mlx);
}

void		rotate_x(t_mlx *mlx, int q)
{
	int		x;
	int		y;
	double	tmp_z;
	double	tmp_y;
	t_map	*map;

	map = mlx->map;
	y = 0;
	while (y < mlx->map->height)
	{
		x = 0;
		while (x < mlx->map->width)
		{
			tmp_z = map->points[y * mlx->map->width + x]->z;
			tmp_y = map->points[y * mlx->map->width + x]->y;
			map->points[y * mlx->map->width + x]->z = (tmp_z
					* (cos(L))) - tmp_y * sin(L) * q;
			map->points[y * mlx->map->width + x]->y = tmp_y
				* cos(L) + tmp_z * sin(L) * q;
			x++;
		}
		y++;
	}
	mlx_clear_window(mlx->mlx, mlx->win);
	draw(mlx);
}

void		rotate_y(t_mlx *mlx, int q)
{
	int		x;
	int		y;
	double	tmp_z;
	double	tmp_x;
	t_map	*map;

	map = mlx->map;
	y = 0;
	while (y < mlx->map->height)
	{
		x = 0;
		while (x < mlx->map->width)
		{
			tmp_z = map->points[y * mlx->map->width + x]->z;
			tmp_x = map->points[y * mlx->map->width + x]->x;
			map->points[y * mlx->map->width + x]->z = tmp_z
				* (cos(L)) - tmp_x * sin(L) * q;
			map->points[y * mlx->map->width + x]->x = tmp_x
				* cos(L) + tmp_z * sin(L) * q;
			x++;
		}
		y++;
	}
	mlx_clear_window(mlx->mlx, mlx->win);
	draw(mlx);
}

void		rotate_z(t_mlx *mlx, int q)
{
	int		x;
	int		y;
	double	tmp_x;
	double	tmp_y;
	t_map	*map;

	map = mlx->map;
	y = 0;
	while (y < mlx->map->height)
	{
		x = 0;
		while (x < mlx->map->width)
		{
			tmp_x = map->points[y * mlx->map->width + x]->x;
			tmp_y = map->points[y * mlx->map->width + x]->y;
			map->points[y * mlx->map->width + x]->x = tmp_x
				* (cos(L)) + tmp_y * sin(L) * q;
			map->points[y * mlx->map->width + x]->y = tmp_y
				* cos(L) - tmp_x * sin(L) * q;
			x++;
		}
		y++;
	}
	mlx_clear_window(mlx->mlx, mlx->win);
	draw(mlx);
}
