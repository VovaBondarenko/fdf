/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 16:45:41 by vbondare          #+#    #+#             */
/*   Updated: 2017/10/16 17:05:29 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		get_isometric_point(t_map *map)
{
	int		x;
	int		y;
	int		tmp_x;
	int		tmp_y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			tmp_x = map->points[y * map->width + x]->x;
			tmp_y = map->points[y * map->width + x]->y;
			map->points[y * map->width + x]->x = (tmp_x
					- map->points[y * map->width + x]->z) / sqrt(2);
			map->points[y * map->width + x]->y = (tmp_x + 2 * tmp_y
					+ map->points[y * map->width + x]->z) / sqrt(6);
			x++;
		}
		y++;
	}
}

void		get_point_distance(t_map *map)
{
	int		mult;
	int		delim;
	int		count;

	count = 0;
	mult = map->width * map->height;
	delim = (!(mult % 2)) ? 2 : 3;
	while (mult /= delim)
		count++;
	map->extra_distance = (int)(POINT_DISTANCE / count) + POINT_DISTANCE;
}

t_point		*add_point(int x, int y, char *str, t_map *map)
{
	t_point *point;

	point = (t_point *)malloc(sizeof(t_point));
	point->x = (double)x * map->extra_distance;
	point->y = (double)y * map->extra_distance;
	point->z = (double)ft_atoi(str) * map->extra_distance;
	point->color = 0xffffff;
	return (point);
}

int			get_points(t_map *map, t_list *lst, int max_length)
{
	char	**split;
	int		x;
	int		y;
	t_list	*tmp_lst;

	y = 0;
	tmp_lst = lst;
	while (tmp_lst)
	{
		split = ft_strsplit(tmp_lst->content, ' ');
		tmp_lst = tmp_lst->next;
		x = 0;
		while (x < max_length)
		{
			if (map->min > ft_atoi(split[x]))
				map->min = ft_atoi(split[x]);
			if (map->max < ft_atoi(split[x]))
				map->max = ft_atoi(split[x]);
			map->points[y * max_length + x] = add_point(x, y, split[x], map);
			x++;
		}
		y++;
	}
	return (1);
}
