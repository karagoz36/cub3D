# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 13:15:22 by tkaragoz          #+#    #+#              #
#    Updated: 2024/10/10 21:21:35 by tkaragoz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SRC_DIR = src
PARSER_DIR = $(SRC_DIR)/parser
OBJ_DIR = obj
LIBFT_DIR = libft

SRC_FILES = main.c
PARSER_FILES = parser.c get_textures.c parser_utils.c check_map.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES)) $(addprefix $(PARSER_DIR)/, $(PARSER_FILES))
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
PARSER_OBJS = $(patsubst $(PARSER_DIR)/%.c, $(OBJ_DIR)/parser/%.o, $(PARSER_FILES)) # 'parser' dosyalarının obje dosyaları için ayrı bir hedef tanımladım.


MLX_DIR = minilibx
MLX = -L $(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm

LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I includes -I $(LIBFT_DIR) #-I $(MLX_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT)  -o $(NAME)
#$(MLX)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/parser/%.o: $(PARSER_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/parser
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
