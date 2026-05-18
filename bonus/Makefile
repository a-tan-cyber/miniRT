NAME = miniRT_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz

SRCS_NAME = \
	src/ft_atod.c \
	src/ft_atof.c \
	src/ft_float_utils.c \
	src/ft_str_is_float.c \
	src/minirt_main.c \
	src/init.c \
	src/vector_basic.c \
	src/vector_extra.c \
	src/vector_bonus.c \
	src/camera_ray.c \
	src/ray_init.c \
	src/cleanup.c \
	src/window.c \
	src/intersect_basic.c \
	src/intersect_ellipsoid.c \
	src/intersect_cylinder_tube.c \
	src/intersect_cylinder_caps.c \
	src/intersect_dispatch.c \
	src/lighting_color.c \
	src/lighting_normal.c \
	src/lighting_main.c \
	src/lighting_utils.c \
	src/lighting_specular.c \
	src/lighting_checker_uv.c \
	src/lighting_checker.c \
	src/lighting_perlin.c \
	src/lighting_perlin_base.c \
	src/lighting_perlin_grad.c \
	src/lighting_perlin_corner.c \
	src/lighting_bump.c \
	src/lighting_threads.c \
	src/lighting_thread_run.c \
	src/parser_validate.c \
	src/parser_data.c \
	src/parser_light_list.c \
	src/parser_data_select.c \
	src/parser_object_bonus.c \
	src/parser_object_bonus_apply.c \
	src/parser_object_common.c \
	src/parser_shapes_ellipsoid.c \
	src/parser_shapes_basic.c \
	src/parser_shapes_cylinder.c \
	src/parser_objects.c \
	src/parser_main.c \
	src/parser_split.c \
	src/object_list.c \
	src/camera_move.c \
	src/input.c \
	src/debug_print.c \
	
SRCS = $(SRCS_NAME)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
# 	$(CC) $(CFLAGS) -I$(LIBFT_DIR)/include -I$(MLX_DIR) -c $< -o $@
	$(CC) $(CFLAGS) $(SPEED) -I$(LIBFT_DIR)/include -I$(MLX_DIR) -c $< -o $@

bonus: all

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
