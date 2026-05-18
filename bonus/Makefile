NAME = ../miniRT_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ../minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz

SRCS_NAME = \
	ft_atod_bonus.c \
	ft_atof_bonus.c \
	ft_float_utils_bonus.c \
	ft_str_is_float_bonus.c \
	minirt_main_bonus.c \
	init_bonus.c \
	vector_basic_bonus.c \
	vector_extra_bonus.c \
	vector_bonus.c \
	camera_ray_bonus.c \
	ray_init_bonus.c \
	cleanup_bonus.c \
	window_bonus.c \
	intersect_basic_bonus.c \
	intersect_ellipsoid_bonus.c \
	intersect_cylinder_tube_bonus.c \
	intersect_cylinder_caps_bonus.c \
	intersect_dispatch_bonus.c \
	lighting_color_bonus.c \
	lighting_normal_bonus.c \
	lighting_main_bonus.c \
	lighting_utils_bonus.c \
	lighting_specular_bonus.c \
	lighting_checker_uv_bonus.c \
	lighting_checker_bonus.c \
	lighting_perlin_bonus.c \
	lighting_perlin_base_bonus.c \
	lighting_perlin_grad_bonus.c \
	lighting_perlin_corner_bonus.c \
	lighting_bump_bonus.c \
	lighting_threads_bonus.c \
	lighting_thread_run_bonus.c \
	parser_validate_bonus.c \
	parser_data_bonus.c \
	parser_light_list_bonus.c \
	parser_data_select_bonus.c \
	parser_object_bonus.c \
	parser_object_bonus_apply_bonus.c \
	parser_object_common_bonus.c \
	parser_shapes_ellipsoid_bonus.c \
	parser_shapes_basic_bonus.c \
	parser_shapes_cylinder_bonus.c \
	parser_objects_bonus.c \
	parser_main_bonus.c \
	parser_split_bonus.c \
	object_list_bonus.c \
	camera_move_bonus.c \
	input_bonus.c \
	debug_print_bonus.c \
	
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
	$(CC) $(CFLAGS) -I$(LIBFT_DIR)/include -I$(MLX_DIR) -c $< -o $@

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
