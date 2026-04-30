TARGET_FILE = ft_cat

$(TARGET_FILE): $(TARGET_FILE).c
	cc -Wall -Werror -Wextra $< -o $@

all: $(TARGET_FILE)

clean:
	rm -f $(TARGET_FILE)

fclean: clean

.PHONY: all clean fclean