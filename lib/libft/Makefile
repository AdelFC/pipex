CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  ft_strlen.c ft_bzero.c ft_putendl_fd.c ft_strlcpy.c ft_strlcat.c \
	  ft_toupper.c ft_tolower.c ft_strdup.c ft_strchr.c ft_strrchr.c \
	  ft_strnstr.c ft_calloc.c ft_strncmp.c ft_memchr.c ft_memset.c \
	  ft_memcpy.c ft_memmove.c ft_memcmp.c ft_itoa.c ft_putnbr_fd.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_strtrim.c ft_substr.c \
	  ft_striteri.c ft_strjoin.c ft_split.c ft_strmapi.c ft_atoi.c \
	  ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	  ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	  ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS = $(SRC:.c=.o)

GREEN = \033[0;92m
BLUE = \033[0;94m
CYAN = \033[0;96m
DEF_COLOR = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) compiled successfully!$(DEF_COLOR)"

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

clean: 
	@rm -f $(OBJS) 
	@echo "$(BLUE)Object files cleaned!$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(CYAN)$(NAME) removed!$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything!$(DEF_COLOR)"

n:
	@norminette -R CheckDefine
	@echo "$(CYAN)Norminette check completed!$(DEF_COLOR)"

.PHONY: all  clean fclean re
