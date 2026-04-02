NAME = libft.a
SRCS_NAME =	\
functions/get_next_line/get_next_line.c							functions/get_next_line/get_next_line_utils.c\
src/array/ft_array.c			src/array/ft_array_cmp.c		src/array/ft_array_cnt.c	src/array/ft_array_cpy.c\
src/array/ft_array_cvt.c		src/array/ft_array_dup.c		src/array/ft_array_iss.c	src/array/ft_array_v.c\
src/array_int/ft_iarr_chk.c		src/array_int/ft_iarr_cpy.c		src/array_int/ft_iarr_print.c\
src/bit/ft_bit_set.c			src/ctype/ctype.c				src/ctype/ctype_special.c	src/ctype/strtobit.c\
src/file/ft_file.c				src/getopt/ft_getopt.c\
src/math/ft_math_p.c			src/math/ft_math_c.c			src/math/ft_math_m.c		src/math/ft_math_u.c\
src/numconv/ft_numconv_base.c	src/numconv/ft_numconv_hex.c	src/numconv/ft_numconv_str.c\
src/queue/ft_queue_1_base.c		src/queue/ft_queue_chk.c		src/queue/ft_queue_n_base.c	src/s_list/ft_s_list.c\
src/s_list/ft_s_list2.c			src/s_list/ft_s_list_each.c		src/stack/ft_stack_base.c	src/stack/ft_stack_chk.c\
src/string/ft_string_cat.c		src/string/ft_string_con.c		src/string/ft_string_mem.c	src/string/ft_string_mem2.c\
src/string/ft_string_substr.c	src/string/ft_string_v.c		src/string/ft_string_vi.c	src/string/ft_string.c			src/string/ft_string_cmp.c\
src/string/ft_string_cpy.c		src/string/ft_string_p.c		src/string/ft_string_t.c	src/string/ft_string_btcmp.c	src/string/ft_put_fd.c		src/string/ft_write_all.c\
src/string/ft_string_cnt.c		src/string/ft_string_m.c		src/string/ft_string_s.c	src/string/ft_string_trim.c		src/utils/ft_utils_free.c\
src/utils/ft_utils_hexdump.c	src/utils/ft_utils_lis.c		src/utils/ft_utils_lis_cir.c\
src/utils/ft_utils_pmem.c		src/utils/ft_utils_search.c		src/utils/ft_utils_sort.c	src/utils/ft_utils_x.c

SRCS = $(SRCS_NAME)
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS) $(NAME)
# 	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re