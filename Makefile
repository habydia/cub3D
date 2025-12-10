CC = cc
CFLAGS = -Wall -Wextra -Werror -I./minilibx-linux -I./libft -MMD -MP
LDFLAGS = -L./minilibx-linux -lmlx -L./libft -lft -lXext -lX11 -lm

SRCS = srcs/main.c \
	   srcs/parsing/parsing.c \
	   srcs/parsing/read_file.c \
	   srcs/parsing/parse_textures.c \
	   srcs/parsing/parse_colors.c \
	   srcs/parsing/parse_map.c \

OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
NAME = cub3D


all: $(NAME)

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
MLX_DIR = minilibx-linux/
MLX = $(MLX_DIR)libmlx.a

-include $(OBJS:.o=.d)

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -L$(LIBFT_DIR) -L$(MLX_DIR) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)/srcs/
	mkdir -p $(OBJ_DIR)/srcs/parsing/

$(LIBFT): force
	$(MAKE) -C $(LIBFT_DIR) bonus

$(MLX): force
	$(MAKE) -C $(MLX_DIR)

force:

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: %.c $(HEADER) Makefile | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -O3 -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re