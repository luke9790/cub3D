# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/20 10:08:45 by lmasetti          #+#    #+#              #
#    Updated: 2023/08/28 10:52:15 by lmasetti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
SRCS = main.c check_map.c  check_map2.c  init.c start.c utils.c utils2.c \
	init_window.c handle_inputs.c
GNL_SRCS = gnl/get_next_line_utils.c gnl/get_next_line.c
OBJS = $(addprefix objs/,$(SRCS:.c=.o)) $(addprefix objs/gnl/,$(notdir $(GNL_SRCS:.c=.o)))
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MINILIBX = -lXext -lX11 -lm -lz
LIB = -L minilibx-linux -lmlx

objs/%.o: %.c
	@mkdir -p objs
	$(CC) -c $(CFLAGS) $< -o $@

objs/gnl/%.o: gnl/%.c
	@mkdir -p objs/gnl
	$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIB) $(MINILIBX) -o $(NAME)

clean:
	rm -rf objs

fclean: clean
	rm -f $(NAME)

re: fclean all

exe:
	./$(NAME) ./maps/map.cub

.PHONY: all clean fclean re
