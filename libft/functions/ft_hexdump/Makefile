TARGET_FILE = src/ft_hexdump

$(TARGET_FILE):
	cc -Wall -Werror -Wextra -Iinclude `find . -name "*.c"` -o $@

all: $(TARGET_FILE)

clean:
	rm -f $(TARGET_FILE)

fclean: clean

remake: clean all

.PHONY: all clean fclean remake