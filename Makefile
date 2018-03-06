# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbondare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/17 11:21:04 by vbondare          #+#    #+#              #
#    Updated: 2017/10/17 11:21:06 by vbondare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror

LIB = libft/libft.a

GNL = gnl/get_next_line.c

SRC = cleaner.c color.c draw.c extra_func.c init.c main.c map.c menu.c pointer.c read_file.c

.PHONY: all re clean

all:
	@make re -C libft/
	@cc -o $(NAME) $(SRC) $(GNL) $(LIB) -lmlx -framework OpenGL -framework AppKit

clean:
	@/bin/rm -f $(NAME)

re:	clean all