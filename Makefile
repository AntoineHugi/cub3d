# Compiler and flags
NAME       		:=	cub3D
CC         		:=	cc
CFLAGS     		:=	-Wall -Werror -Wextra #-fsanitize=address -g
RM         		:=	rm -f
SRC_DIR			:=	./src
SRC_BONUS_DIR	:=	./src_bonus
LIBFT_DIR		:=	./src/libft/
LIBFT			:=	./src/libft/libft.a
DEF_COLOUR 		:=	\033[0;39m
GREEN      		:=	\033[1;92m

# OS-specific flags
ifeq ($(shell uname), Linux)
	MLX_DIR		:=	./minilibx-linux/
	MLX_URL		:=	https://github.com/42Paris/minilibx-linux.git
	MLX			:=	$(MLX_DIR)/libmlx.a
    MLX_FLAGS	:=	 -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
else
	MLX_DIR		:=	./minilibx_macos/
	MLX			:=	$(MLX_DIR)/libmlx.a
    INCLUDES 	:=	-I/opt/X11/include -Imlx
	MLX_FLAGS	:=	-I/opt/X11/include -I/lib/minilibx_macos/ -lft -L$(MLX_DIR) -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

# Sources and Objects
SRCS       		:=	$(addprefix $(SRC_DIR)/, error.c freeing.c initialisation_game.c initialisation_raycasting.c \
						key_hooks.c main.c map_creation.c move_player.c move_view.c \
						parsing_element.c parsing_file.c raycasting_calculation.c render_map.c \
						validation_color.c validation_element.c validation_file.c validation_map.c )

SRCS_BONUS 		:=	$(addprefix $(SRC_BONUS_DIR)/, main_bonus.c \
						utils_bonus.c)
OBJS			:=	$(SRCS:.c=.o)
OBJS_BONUS		:=	$(SRCS_BONUS:.c=.o)


all : $(LIBFT) $(MLX) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) $(MLX_FLAGS)
	@echo "$(GREEN) $(NAME) ✔︎ $(DEF_COLOUR)"
	@echo "$(GREEN) Usage: ./$(NAME) ./maps/valid/'select a map' ✔︎ $(DEF_COLOUR)"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN) Compiled libft  ✔︎ $(DEF_COLOUR)"

$(MLX):
ifeq ($(shell uname), Linux)
	@if [ ! -d "$(MLX_DIR)" ]; then \
		git clone $(MLX_URL) $(MLX_DIR); \
	fi
	@$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1
	@echo "$(GREEN) minilibx-linux installed! ✔︎ $(DEF_COLOUR)"
else
	@echo "$(GREEN) minilibx-macos already installed! ✔︎ $(DEF_COLOUR)"
endif

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

bonus: $(OBJS_BONUS) $(LIBFT) $(MLX)
	$(MAKE) -C $(MLX_DIR)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS_BONUS) -L$(LIBFT_DIR) $(MLX_FLAGS)
	@echo "$(GREEN)fdf bonus ✔︎$(DEF_COLOUR)"

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	@echo "$(GREEN)Object files removed!$(DEF_COLOUR)"
fclean: clean
	rm -f $(NAME)
	rm -rf $(MLX_DIR)
	$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(NAME) removed!"
re: fclean all
.PHONY: clean fclean re all
