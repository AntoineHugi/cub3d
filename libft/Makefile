CUR_DIR = $(shell pwd)

NAME = libft.a

CC = cc

RM = rm -f

CFLAGS += -Wall -Wextra -Werror

MY_SOURCES = $(addprefix $(CUR_DIR)/, ft_atoi.c ft_bzero.c ft_calloc.c \
					ft_isalnum.c ft_isalpha.c ft_isascii.c \
					ft_isdigit.c ft_isprint.c ft_itoa.c \
					ft_memchr.c ft_memcmp.c ft_memcpy.c \
					ft_memmove.c ft_memset.c \
					ft_split.c ft_strchr.c ft_strdup.c \
					ft_striteri.c ft_strjoin.c ft_strlcat.c \
	     			ft_strlcpy.c ft_strlen.c ft_strmapi.c \
	     			ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	    			ft_strtrim.c ft_substr.c \
					get_next_line.c get_next_line_utils.c)

MY_HEADERS = libft.h

MY_OBJECTS = $(MY_SOURCES:.c=.o)

all:	$(NAME)
	@echo "Compiled libft"

$(NAME): $(MY_OBJECTS)
	@ar rcs $(NAME) $(MY_OBJECTS) 

%.o: %.c $(MY_HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

clean: 	
	@$(RM) $(MY_OBJECTS) $(MY_OBJECTS_BONUS)

fclean: clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re bonus
