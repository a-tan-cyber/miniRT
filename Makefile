NAME		= miniRT
NAME_BONUS	= miniRT_bonus

MANDATORY_DIR	= mandatory
BONUS_DIR	= bonus

.PHONY: all bonus clean fclean re FORCE

all: $(NAME)

$(NAME): FORCE
	$(MAKE) -C $(MANDATORY_DIR)

bonus: $(NAME_BONUS)

$(NAME_BONUS): FORCE
	$(MAKE) -C $(BONUS_DIR)

clean:
	$(MAKE) -C $(MANDATORY_DIR) clean
	$(MAKE) -C $(BONUS_DIR) clean

fclean:
	$(MAKE) -C $(MANDATORY_DIR) fclean
	$(MAKE) -C $(BONUS_DIR) fclean

re: fclean all

FORCE: