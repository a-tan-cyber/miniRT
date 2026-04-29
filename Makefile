NAME = miniRT
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
	src/camera_ray.c \
	src/ray_init.c \
	src/cleanup.c \
	src/window.c \
	src/intersect_basic.c \
	src/intersect_cylinder_tube.c \
	src/intersect_cylinder_caps.c \
	src/intersect_dispatch.c \

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
