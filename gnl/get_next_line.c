/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 11:51:52 by vbondare          #+#    #+#             */
/*   Updated: 2017/09/14 16:06:20 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_node	*ft_create_node(int fd)
{
	t_node		*tmp;

	tmp = (t_node*)malloc(sizeof(t_node));
	tmp->fd = fd;
	tmp->str = ft_strnew(0);
	tmp->next = NULL;
	return (tmp);
}

static t_node	*ft_check_fd(int fd, t_node *head)
{
	t_node		*tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->fd == fd)
			break ;
		else if (!(tmp->next))
			tmp->next = ft_create_node(fd);
		tmp = tmp->next;
	}
	return (tmp);
}

static int		ft_save_str(t_node *tmp, char buffer[], char **line)
{
	if (HAVE_NEW_LINE)
	{
		*line = ft_strsub(tmp->str, 0, STR_COUNT);
		tmp->str += (STR_COUNT);
		return (1);
	}
	else if ((!HAVE_NEW_LINE) && EMPTY_BUFFER)
	{
		*line = ft_strdup(tmp->str);
		ft_memset(tmp->str, 0, sizeof(tmp->str));
		return (1);
	}
	return (0);
}

static int		can_save_str(t_node *tmp, char *buffer, char **line)
{
	if ((LINE_FEED) || (!LINE_FEED && EMPTY_BUFFER))
		if (ft_save_str(tmp, buffer, line) == 1)
			return (1);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_node	*head = NULL;
	t_node			*tmp;
	int				b_tmp;
	char			buffer[BUFF_SIZE + 1];

	if (NOT_VALID_FD || CANT_READ || NOT_VALID_LINE || NOT_VALID_BUFFER)
		return (-1);
	if (head == NULL)
		head = ft_create_node(fd);
	tmp = ft_check_fd(fd, head);
	while ((b_tmp = read(fd, buffer, BUFF_SIZE)) >= 0)
	{
		if (b_tmp < BUFF_SIZE)
			buffer[b_tmp] = '\0';
		tmp->str = ft_strjoin(tmp->str, buffer);
		if (tmp->str[0] == '\n')
			tmp->str += 1;
		if (ft_strlen(tmp->str) > 0 && can_save_str(tmp, buffer, line))
			return (1);
		else if (b_tmp == 0)
			return (0);
	}
	return (0);
}
