NAME = ../miniRT
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ../minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz

SRCS_NAME = \
	ft_atod.c \
	ft_atof.c \
	ft_float_utils.c \
	ft_str_is_float.c \
	minirt_main.c \
	init.c \
	vector_basic.c \
	vector_extra.c \
	camera_ray.c \
	ray_init.c \
	cleanup.c \
	window.c \
	intersect_basic.c \
	intersect_cylinder_tube.c \
	intersect_cylinder_caps.c \
	intersect_dispatch.c \
	lighting_color.c \
	lighting_normal.c \
	lighting_main.c \
	parser_validate.c \
	parser_data.c \
	parser_objects.c \
	parser_main.c \
	parser_split.c \
	object_list.c \
	camera_move.c \
	input.c \
	debug_print.c \
	
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

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
