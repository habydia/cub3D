CC = cc
CFLAGS = -Wall -Wextra -Werror -I./minilibx-linux -I./libft -MMD -MP
LDFLAGS = -L./minilibx-linux -lmlx -L./libft -lft -lXext -lX11 -lm

SRCS = srcs/main.c \
	srcs/parsing/parsing.c \
	srcs/parsing/read_file.c \
	srcs/parsing/parse_textures.c \
	srcs/parsing/parse_colors.c \
	srcs/parsing/map_processing.c \
	srcs/parsing/map_validation.c \
	srcs/textures/charge_textures.c \
	srcs/textures/free_textures.c \
	srcs/textures/sync_textures.c \
	srcs/textures/texture_loader.c \
	srcs/textures/texture_ptrs.c \
	srcs/keyboard/handle_key.c \
	srcs/keyboard/handle_key_utils.c \
	srcs/render_3d/render.c \
	srcs/render_3d/draw_floor_and_ceilling.c \
	srcs/raycasting/raycasting.c \
	srcs/raycasting/raycasting_utils_calculate_step.c \
	srcs/raycasting/raycasting_utils_calculate_wall_distance.c \
	srcs/raycasting/raycasting_utils_dda_algo.c \
	srcs/raycasting/raycasting_utils_draw_vertical_line.c \
	srcs/raycasting/raycasting_utils_draw_vertical_line_utils_render_wall_pixel_column.c \
	srcs/raycasting/raycasting_utils_draw_vertical_line_utils_wall_texture_fill.c \
	srcs/raycasting/raycasting_utils_init_ray.c \
	srcs/raycasting/raycasting_utlils_draw_vertical_line_utils_texture_mapping.c \
	srcs/player/init_player.c \
	srcs/player/update_player.c \
	srcs/player/wall_collision_bonus.c \
	srcs/minimap/draw_minimap_bonus.c \
	srcs/window/open_window.c \
	srcs/window/window_events.c \
	srcs/game/init_data_game_key.c

SRCS_BONUS =

OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=$(OBJ_DIR)/%.o)
NAME = cub3D

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
MLX_DIR = minilibx-linux/
MLX = $(MLX_DIR)libmlx.a

-include $(OBJS:.o=.d)
-include $(OBJS_BONUS:.o=.d)

all: $(NAME)

bonus: $(OBJ_DIR) $(OBJS) $(OBJS_BONUS) $(LIBFT) $(MLX)
	$(CC) $(OBJS) $(OBJS_BONUS) $(CFLAGS) $(LDFLAGS) -L$(LIBFT_DIR) -L$(MLX_DIR) -o $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -L$(LIBFT_DIR) -L$(MLX_DIR) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)/srcs/
	mkdir -p $(OBJ_DIR)/srcs/parsing/
	mkdir -p $(OBJ_DIR)/srcs/render_3d/
	mkdir -p $(OBJ_DIR)/srcs/minimap/
	mkdir -p $(OBJ_DIR)/srcs/raycasting/
	mkdir -p $(OBJ_DIR)/srcs/player/
	mkdir -p $(OBJ_DIR)/srcs/window/
	mkdir -p $(OBJ_DIR)/srcs/game/
	mkdir -p $(OBJ_DIR)/srcs/keyboard/
	mkdir -p $(OBJ_DIR)/srcs/textures/
	mkdir -p $(OBJ_DIR)/srcs/handle_textures/

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

.PHONY: all bonus clean fclean re