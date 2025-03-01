CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex

# Directories
FT_PRINTF_DIR = lib/ftprintf
LIBFT_DIR = lib/libft
UTILS_DIR = utils
SRC_DIR = src
INCS = -I includes

SRC = $(SRC_DIR)/pipex.c $(SRC_DIR)/utils.c 

# Object files
OBJS = $(SRC:.c=.o) $(UTILS:.c=.o)

# Libraries
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
LIBFT = $(LIBFT_DIR)/libft.a

# Colors
GREEN = \033[0;92m
BLUE = \033[0;94m
CYAN = \033[0;96m
YELLOW = \033[0;93m
DEF_COLOR = \033[0m

all: $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) -L$(FT_PRINTF_DIR) -lftprintf \
        -L$(GNL_DIR) -lftgnl -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo ""
	@echo "$(GREEN)╔════════════════════════════╗$(DEF_COLOR)"
	@echo "$(GREEN)║       PIPEX COMPILED!      ║$(DEF_COLOR)"
	@echo "$(GREEN)╚════════════════════════════╝$(DEF_COLOR)"
	@echo ""

# Libraries
$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR) --no-print-directory
	@echo "$(CYAN)ftprintf compiled!$(DEF_COLOR)"

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory
	@echo "$(CYAN)libft compiled!$(DEF_COLOR)"

# Compilation des fichiers objets
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(UTILS_DIR)/%.o: $(UTILS_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

# Clean
clean:
	@rm -f $(OBJS)
	@make -C $(FT_PRINTF_DIR) clean --no-print-directory
	@make -C $(LIBFT_DIR) clean --no-print-directory
	@echo "$(BLUE)Object files cleaned!$(DEF_COLOR)"

# Full clean
fclean: clean
	@rm -f $(NAME)
	@make -C $(FT_PRINTF_DIR) fclean --no-print-directory
	@make -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "$(BLUE)All compiled files cleaned!$(DEF_COLOR)"

# Re
re: fclean all
	@echo "$(GREEN)        PROJECT REBUILT!      $(DEF_COLOR)"
	@echo ""

# Norminette
n:
	@norminette -R CheckDefine
	@echo "$(YELLOW)Norminette check completed!$(DEF_COLOR)"

.PHONY: all clean fclean re $(NAME)
