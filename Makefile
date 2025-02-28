# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 15:28:58 by marvin            #+#    #+#              #
#    Updated: 2024/10/30 15:28:58 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
MLX_FLAGS = -L./mlx-linux -lX11 -lXext -lm
SRCS_DIR = srcs/
SOURCES = checks/error.c \
		  checks/map_check.c \
          graphics/ren.c \
          graphics/utils.c \
          help/innit_map.c \
          help/player.c \
          help/map.c \
          others/handle.c \
          others/move.c \
          others/msg.c \
          main.c

MLX_PATH = mlx/
MLX_LIB = $(MLX_PATH)libmlx.a

LIBFT_PATH = lib/libft/
LIBFT_LIB = $(LIBFT_PATH)libft.a

GNL_DIR = get_next_line/
GNL = get_next_line.c \
      get_next_line_utils.c

GNL_OBJS = $(addprefix $(GNL_DIR), $(GNL:.c=.o))
OBJECTS = $(addprefix $(SRCS_DIR), $(SOURCES:.c=.o))

all: subsystems $(NAME)

$(SRCS_DIR)%.o : $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -Imlx -c -o $@ $<

$(GNL_DIR)%.o : $(GNL_DIR)%.c
	$(CC) $(CFLAGS) -Imlx -c -o $@ $<

subsystems:
	@make -C $(MLX_PATH) all
	@make -C $(LIBFT_PATH) all

$(NAME): $(OBJECTS) $(GNL_OBJS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJECTS) $(MLX_LIB) $(LIBFT_LIB) $(GNL_OBJS) -o $(NAME)

clean:
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJECTS) $(GNL_OBJS)

fclean:
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)
