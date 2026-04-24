NAME = minirt
SRCS_NAME =	\
	src/ft_atod.c \
	src/ft_atof.c \
	src/ft_float_utils.c \
	src/ft_str_is_float.c \
	src/minirt_main.c \

SRCS = $(SRCS_NAME)
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(NAME) $(OBJS)

%.o: %.c
# 	cc -Wall -Wextra -Werror -c $< -o $@
	cc -lmlx -lXext -lX11 -c $< -o $@

all: $(NAME)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS) $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
