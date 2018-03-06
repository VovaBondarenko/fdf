/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 16:45:20 by vbondare          #+#    #+#             */
/*   Updated: 2017/10/16 17:09:05 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			read_file(int fd, t_list **lst)
{
	t_list	*tmp;
	char	*line_res;
	int		count_line;
	int		b_tmp;

	count_line = -1;
	while ((b_tmp = get_next_line(fd, &line_res)) > 0)
	{
		(count_line == -1) ? count_line = get_map_width(line_res) : 0;
		tmp = ft_lstnew(line_res, ft_strlen(line_res) + 1);
		if (tmp == NULL)
			return (0);
		ft_lstadd(lst, tmp);
		if (count_line != get_map_width(line_res))
			return (0);
		ft_strdel(&line_res);
	}
	if (count_line < 0)
		return (0);
	list_reverse(lst);
	return (1);
}

int			parse_file(int fd, t_map **map)
{
	t_list	*lst;
	t_point	*points;
	int		width;
	int		height;

	lst = NULL;
	if (!read_file(fd, &lst))
		return (clean_lst(&lst));
	width = get_map_width(lst->content);
	height = get_map_heigth(lst);
	*map = get_map(width, height);
	get_point_distance(*map);
	if (!get_points(*map, lst, width) || *map == NULL)
		return (clean_map(map));
	get_point_color(*map);
	get_isometric_point(*map);
	get_win_size(*map);
	get_map_centre(*map);
	return (1);
}
