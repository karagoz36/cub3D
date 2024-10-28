NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
SRC_DIR = srcs
OBJ_DIR = obj

PARSER_DIR = $(SRC_DIR)/parser
MOVEMENT_DIR = $(SRC_DIR)/movement
RENDER_DIR = $(SRC_DIR)/render

SRC_FILES = main.c init_data.c free_data.c mlx_utils.c hooks.c calculations.c
PARSER_FILES = check_map.c get_textures.c parser_utils.c parser.c
RENDER_FILES = collision.c ray.c render_utils.c textures.c
MOVEMENT_FILES = movement.c movement2.c

SRCS =  $(addprefix $(SRC_DIR)/, $(SRC_FILES)) \
		$(addprefix $(PARSER_DIR)/, $(PARSER_FILES)) \
		$(addprefix $(MOVEMENT_DIR)/, $(MOVEMENT_FILES)) \
		$(addprefix $(RENDER_DIR)/, $(RENDER_FILES)) \

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = mlx
MLX = -L $(MLX_DIR) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX_LIB = $(MLX_DIR)/libmlx.a
INCLUDES = -I includes -I $(LIBFT_DIR) -I $(MLX_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(LIBFT)  -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/parser/%.o: $(PARSER_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/parser
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/movement/%.o: $(MOVEMENT_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/movement
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/render/%.o: $(RENDER_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/render
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX_LIB):
	make -C $(MLX_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
