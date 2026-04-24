NAME = minirt
SRCS_NAME =	\
	src/ft_atod.c \
	src/ft_atof.c \
	src/ft_float_utils.c \
	src/ft_str_is_float.c \
	src/minirt_main.c \

SRCS = $(SRCS_NAME)
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/mlx.a
$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT)
	cc $(OBJS) -I$(LIBFT) -I$(MLX) -lXext -lX11 -o $(NAME)

%.o: %.c
# 	cc -Wall -Wextra -Werror -c $< -o $@
	cc -c $< -o $@

all: $(LIBFT) $(MLX) $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
