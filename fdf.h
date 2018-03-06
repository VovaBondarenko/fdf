/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 16:47:12 by vbondare          #+#    #+#             */
/*   Updated: 2017/10/16 18:06:52 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H

# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "minilibx_macos/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>

# define POINT_DISTANCE 10
# define L 3.14 / 180

typedef struct	s_brez
{
	int			sign_a;
	int			sign_b;
	int			x;
	int			y;
}				t_brez;

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_point;

typedef struct	s_map
{
	int			width;
	int			height;
	int			min;
	int			max;
	int			extra_distance;
	int			move_x;
	int			move_y;
	int			img_size;
	t_point		**points;
	int			i_move_x;
	int			i_move_y;
}				t_map;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	t_map		*map;
	int			map_width;
	int			map_heigth;
}				t_mlx;

t_mlx			*init(char *name, t_map *map);
int				parse_file(int fd, t_map **map);
t_point			*add_point(int x, int y, char *str, t_map *map);
int				get_points(t_map *map, t_list *lst, int max_length);
void			get_point_distance(t_map *map);
void			get_isometric_point(t_map *map);
int				get_counts(char *line);
void			list_reverse(t_list **lst);
int				get_map_width(char *str);
int				get_map_heigth(t_list *lst);
t_map			*get_map(int width, int height);
int				clean_map(t_map **map);
void			get_win_size(t_map *map);
void			get_map_centre(t_map *map);
void			move_fdf(t_mlx *mlx, int keycode);
int				clean_lst(t_list **lst);
void			draw(t_mlx *mlx);
int				get_color(t_map *map, double z);
void			get_point_color(t_map *map);
void			zoom(t_mlx *mlx, int keycode);
void			rotate_x(t_mlx *mlx, int q);
void			rotate_y(t_mlx *mlx, int q);
void			rotate_z(t_mlx *mlx, int q);
void			change_rotation(t_mlx *mlx, int keycode);

#endif
