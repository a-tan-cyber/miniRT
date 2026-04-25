NAME = minirt
SRCS_NAME =	\
	src/ft_atod.c \
	src/ft_atof.c \
	src/ft_float_utils.c \
	src/ft_str_is_float.c \
	src/minirt_main.c \

SRCS = $(SRCS_NAME)
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(MLX) $(NAME)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a
$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	cc $(OBJS) $(LIBFT) $(MLX) -lXext -lX11 -lm -o $(NAME)

%.o: %.c
# 	cc -Wall -Wextra -Werror -c $< -o $@
	cc -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
