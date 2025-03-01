CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex

# Directories
FT_PRINTF_DIR = lib/ftprintf
GNL_DIR = lib/get_next_line
LIBFT_DIR = lib/libft
UTILS_DIR = utils
SRC_DIR = src
INCS = -I includes

SRC = $(SRC_DIR)/pipex.c  $(SRC_DIR)/utils.c 

# Object files
OBJS = $(SRC:.c=.o) $(UTILS:.c=.o)

# Colors
GREEN = \033[0;92m
BLUE = \033[0;94m
CYAN = \033[0;96m
YELLOW = \033[0;93m

all: $(FT_PRINTF_DIR)/libftprintf.a $(GNL_DIR)/libgnl.a $(LIBFT_DIR)/libft.a $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -L$(FT_PRINTF_DIR) -lftprintf \
        -L$(GNL_DIR) -lftgnl -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!"

# Libraries
$(FT_PRINTF_DIR)/libftprintf.a:
	@make -C $(FT_PRINTF_DIR)
	@echo "$(CYAN)libftprintf compiled!"

$(GNL_DIR)/libgnl.a:
	@make all -C $(GNL_DIR) --no-print-directory
	@echo "$(CYAN)get_next_line compiled!"

$(LIBFT_DIR)/libft.a:
	@make -C $(LIBFT_DIR)
	@echo "$(CYAN)libft compiled!"

# Rules
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(UTILS_DIR)/%.o: $(UTILS_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make -C $(FT_PRINTF_DIR) clean
	@make -C $(GNL_DIR) clean
	@make -C $(LIBFT_DIR) clean
	@echo "$(BLUE)Object files cleaned!"

fclean: clean
	@rm -f $(NAME)
	@make -C $(FT_PRINTF_DIR) fclean
	@make -C $(GNL_DIR) fclean
	@make -C $(LIBFT_DIR) fclean
	@echo "$(BLUE)All compiled files cleaned!"

re: fclean all
	@echo "$(GREEN)Project fully rebuilt!"

n:
	@norminette -R CheckDefine
	@echo "$(YELLOW)Norminette check completed!"

.PHONY: all clean fclean re
