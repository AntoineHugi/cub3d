# Compiler and flags
NAME       		:=	cub3D
CC         		:=	cc
CFLAGS     		:=	-Wall -Werror -Wextra #-fsanitize=address -g
RM         		:=	rm -f
SRC_DIR			:=	./src
SRC_BONUS_DIR	:=	./src_bonus
LIBFT_DIR		:=	libft/
LIBFT			:=	libft/libft.a
DEF_COLOUR 		:=	\033[0;39m
GREEN      		:=	\033[1;92m

# OS-specific flags
ifeq ($(shell uname), Linux)
	MLX_DIR		:=	./minilibx_linux/
	MLX_URL		:=	https://github.com/42Paris/minilibx-linux.git
	MLX			:=	$(MLX_DIR)/libmlx.a
	MLX_FLAGS	:=	-lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
else
	MLX_DIR		:=	./minilibx_macos/
	MLX			:=	$(MLX_DIR)/libmlx.a
	INCLUDES 	:=	-I/opt/X11/include -Imlx
	MLX_FLAGS	:=	-I/opt/X11/include -I/lib/minilibx_macos/ -lft -L$(MLX_DIR) -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

# Source files grouped by directory

PARSER_DIR = $(SRC_DIR)/parser
GAME_DIR = $(SRC_DIR)/game
PLAYER_DIR = $(SRC_DIR)/player
UTILS_DIR = $(SRC_DIR)/utils

SRCS =  src/main.c \
        $(PARSER_DIR)/parser.c \
        $(PARSER_DIR)/parser_config.c \
        $(PARSER_DIR)/parser_map.c \
        $(PARSER_DIR)/parser_utils.c \
        $(GAME_DIR)/game_init.c \
        $(GAME_DIR)/raycaster.c \
        $(GAME_DIR)/render.c \
        $(PLAYER_DIR)/player_init.c \
        $(PLAYER_DIR)/player_controls.c \
        $(UTILS_DIR)/error.c \
        $(UTILS_DIR)/memory.c \
        $(UTILS_DIR)/utils.c

SRCS_BONUS 		:=	$(addprefix $(SRC_BONUS_DIR)/, colours_bonus.c draw_bonus.c \
						keys_bonus.c main_bonus.c parse_bonus.c render_bonus.c \
						mapread_bonus.c utils_bonus.c)
OBJS			:=	$(SRCS:.c=.o)
OBJS_BONUS		:=	$(SRCS_BONUS:.c=.o)


all : $(LIBFT) $(MLX) $(NAME)
$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) $(MLX_FLAGS)
	@echo "$(GREEN) $(NAME) ✔︎ $(DEF_COLOUR)"

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
ifeq ($(shell uname), Linux)
	if [ ! -d "$(MLX_DIR)" ]; then \
		git clone $(MLX_URL) $(MLX_DIR); \
	fi
	$(MAKE) -C $(MLX_DIR)
	@echo "$(GREEN) minilibx-linux installed! ✔︎ $(DEF_COLOUR)"
else
	@echo "$(GREEN) minilibx-macos already installed! ✔︎ $(DEF_COLOUR)"
endif

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

bonus: $(OBJS_BONUS) $(LIBFT) $(MLX)
	$(MAKE) -C $(MLX_DIR)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS_BONUS) -L$(LIBFT_DIR) $(MLX_FLAGS)
	@echo "$(GREEN)cub3d bonus ✔︎$(DEF_COLOUR)"

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(MAKE) clean -C $(LIBFT_DIR)
	@echo "$(GREEN)Object files removed!$(DEF_COLOUR)"
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(NAME) removed!"
re: fclean all
.PHONY: clean fclean re all
