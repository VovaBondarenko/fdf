/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:00:13 by vbondare          #+#    #+#             */
/*   Updated: 2017/09/14 13:04:55 by vbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# define HAVE_NEW_LINE (ft_strchr(tmp->str, '\n'))
# define NOT_VALID_FD (fd < 0)
# define NOT_VALID_LINE (line == NULL)
# define CANT_READ ((read(fd,buffer,0)) == -1 && head == NULL)
# define EMPTY_BUFFER (ft_strlen(buffer) == 0)
# define LINE_FEED (ft_strchr(tmp->str, 10))
# define STR_COUNT (ft_strchr(tmp->str, 10) - tmp->str)
# define NOT_VALID_BUFFER (!(ft_memset(buffer, 0, BUFF_SIZE + 1)))
# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_node
{
	int				fd;
	char			*str;
	struct s_node	*next;
}					t_node;
int					get_next_line(const int fd, char **line);

#endif
