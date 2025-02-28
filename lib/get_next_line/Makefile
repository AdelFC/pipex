NAME = libftgnl.a
SRC = get_next_line_utils.c get_next_line.c 
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRC:.c=.o)

GREEN = \033[0;92m
BLUE = \033[0;94m
CYAN = \033[0;96m

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@echo "$(GREEN)get_next_line compiled!$(DEF_COLOR)"

.c.o:
	@cc $(CFLAGS) -c $< -o $@

clean: 
	@rm -f $(OBJS)
	@echo "$(BLUE)get_next_line object files cleaned!$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME) libft.a
	@echo "$(CYAN)get_next_line executable files cleaned!$(DEF_COLOR)"

re: fclean
	@make all
	@echo "$(GREEN)Cleaned and rebuilt everything for get_next_line!$(DEF_COLOR)"

.PHONY: clean fclean re all