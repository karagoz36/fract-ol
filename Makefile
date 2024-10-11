# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/02 12:51:30 by tkaragoz          #+#    #+#              #
#    Updated: 2024/07/09 16:03:03 by tkaragoz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx -Ilibft -g3
MLXFLAGS = -Lmlx -lmlx -lX11 -lXext -lm
SRC_FILES = main.c handle_mlx.c fractal_setup.c julia_extra.c
SRCS = $(SRC_FILES)
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a
MLX = mlx/libmlx.a

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLXFLAGS)

$(LIBFT):
	make -C libft

$(MLX):
	make -C mlx

clean:
	make -C libft clean
	make -C mlx clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re