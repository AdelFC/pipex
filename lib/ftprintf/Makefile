CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

# Sources
SRC = ft_printf.c ft_printf_utils.c ft_printf_utils2.c

# Object files
OBJS = $(SRC:.c=.o)

# Colors
GREEN = \033[0;92m
BLUE = \033[0;94m
CYAN = \033[0;96m
YELLOW = \033[0;93m
DEF_COLOR = \033[0m

# Compilation principale
all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

# Compilation des fichiers objets
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	@rm -f $(OBJS)
	@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"

# Nettoyage total
fclean: clean
	@rm -f $(NAME)
	@echo "$(CYAN)ft_printf library removed!$(DEF_COLOR)"

# Recompile tout
re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

.PHONY: all clean fclean re $(NAME)
