# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 13:15:22 by tkaragoz          #+#    #+#              #
#    Updated: 2024/10/07 13:57:30 by tkaragoz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj
LIBT_DIR = libft

SRC_FILES = main.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

MLX_DIR = minilibx
MLX = -L $(MLX_DIR) - lmlx - framework OpenGL -framework AppKit

LIBFT = $(LIBT_DIR)/libft.a

INCLUDES = -I includes -I $(LIBT_DIR) - I $(MLX_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBT_DIR)

re: fclean all

.PHONY: all clean fclean re
