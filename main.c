/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 16:43:25 by vbondare          #+#    #+#             */
/*   Updated: 2017/10/17 11:49:53 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	exit_fdf(void)
{
	ft_putendl("Input not valid");
	exit(0);
}

static int		rotate(int keycode, t_mlx *mlx)
{
	if (keycode == 83)
		rotate_x(mlx, 1);
	else if (keycode == 86)
		rotate_y(mlx, 1);
	else if (keycode == 84)
		rotate_x(mlx, -1);
	else if (keycode == 87)
		rotate_y(mlx, -1);
	else if (keycode == 85)
		rotate_z(mlx, -1);
	else if (keycode == 88)
		rotate_z(mlx, 1);
	return (0);
}

static int		key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	else if (keycode >= 123 && keycode <= 126)
		move_fdf(mlx, keycode);
	else if (keycode == 69 || keycode == 78)
		zoom(mlx, keycode);
	else if (keycode >= 83 && keycode <= 88)
		rotate(keycode, mlx);
	return (1);
}

static	int		menu(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->win, 0,
			10, 0xffff4d, "Press :");
	mlx_string_put(mlx->mlx, mlx->win, 0, 28,
			0xffff4d, "6 or 3 to rotate z axis");
	mlx_string_put(mlx->mlx, mlx->win, 0, 42,
			0xffff4d, "4 or 5 to rotate y axis");
	mlx_string_put(mlx->mlx, mlx->win, 0, 54,
			0xffff4d, "1 or 2 to rotate x axis");
	mlx_string_put(mlx->mlx, mlx->win, 0, 66,
			0xffff4d, "+ or - to zoom");
	mlx_string_put(mlx->mlx, mlx->win, 0, 78,
			0xffff4d, "Arrows to move your fdf");
	return (1);
}

int				main(int argc, char **argv)
{
	t_map		*map;
	t_mlx		*mlx;
	int			fd;

	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		exit_fdf();
	fd = open(argv[1], O_RDONLY);
	if (!parse_file(fd, &map))
		exit_fdf();
	mlx = init("FDF", map);
	mlx->map = map;
	draw(mlx);
	mlx_hook(mlx->win, 2, 0, key_hook, mlx);
	mlx_expose_hook(mlx->win, menu, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
