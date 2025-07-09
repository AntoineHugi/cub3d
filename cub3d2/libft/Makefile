# Compiler and flags
NAME        := libft.a
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -fPIC
AR          := ar
ARFLAGS     := rcs
DEF_COLOR   := \033[0;39m
GREEN       := \033[0;92m

# Sources and Objects
SRCS        := ft_atoi.c  get_next_line.c  ft_isalnum.c  ft_isdigit.c  ft_lstadd_back.c \
				ft_lstdelone.c ft_lstmap.c ft_memmove.c ft_split.c ft_strlcat.c ft_freetab.c \
				ft_strrchr.c ft_lstnew.c ft_memset.c ft_strchr.c ft_strlcpy.c ft_isspace.c \
				ft_strtrim.c ft_bzero.c ft_isalpha.c ft_isprint.c ft_lstadd_front.c \
				ft_lstiter.c ft_lstsize.c ft_putchar_fd.c ft_strcmp.c ft_strlen.c \
				ft_substr.c ft_memchr.c ft_putendl_fd.c ft_strdup.c ft_strmapi.c \
				ft_tolower.c ft_calloc.c ft_isascii.c ft_itoa.c ft_lstclear.c ft_atol.c \
				ft_lstlast.c ft_memcmp.c ft_putnbr_fd.c ft_striteri.c ft_strncmp.c \
				ft_toupper.c ft_memcpy.c ft_putstr_fd.c ft_strjoin.c ft_strnstr.c ft_ltoa.c \

OBJS        := $(SRCS:.c=.o)

# Targets and commands
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^
	@echo "$(GREEN) libft ✔︎$(DEF_COLOR)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
