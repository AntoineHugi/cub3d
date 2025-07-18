# Compiler and flags
NAME			:=	cub3D
NAME_BONUS		:=	cub3D_bonus
CC				:=	cc
CFLAGS			:=	-Wall -Werror -Wextra #-fsanitize=address -g
RM				:=	rm -f
SRC_DIR			:=	./src
SRC_BONUS_DIR	:=	./src_bonus
LIBFT_DIR		:=	./libft/
LIBFT			:=	./src/libft/libft.a
DEF_COLOUR 		:=	\033[0;39m
GREEN			:=	\033[1;92m

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
SRC				:=	error.c freeing.c initialisation_game.c initialisation_raycasting.c \
					key_hooks.c main.c map_creation.c move_player.c move_view.c \
					parsing_element.c parsing_file.c raycasting_calculation.c render_map.c \
					validation_color.c validation_element.c validation_file.c \
					validation_map.c
SRC_BONUS		:=	animation.c minimap.c mouse_hook.c sprite.c utils.c error.c \
					freeing.c initialisation_game.c initialisation_raycasting.c \
					key_hooks.c main.c map_creation.c move_player.c \
					move_view.c parsing_element.c parsing_file.c \
					raycasting_calculation.c render_map.c validation_color.c \
					validation_element.c validation_file.c validation_map.c

SRCS       		:=	$(addprefix $(SRC_DIR)/, $(SRC))
SRCS_BONUS 		:=	$(addprefix $(SRC_BONUS_DIR)/, $(SRC_BONUS))
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
	@$(MAKE) -C $(MLX_DIR)
	@echo "$(GREEN) minilibx-macos already installed! ✔︎ $(DEF_COLOUR)"
endif

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

bonus: $(LIBFT) $(MLX) $(NAME_BONUS)
	@$(MAKE) -C $(MLX_DIR)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) -L$(LIBFT_DIR) $(MLX_FLAGS)
	@echo "$(GREEN) cub3D bonus ✔︎$(DEF_COLOUR)"

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) -L$(LIBFT_DIR) $(MLX_FLAGS)
	@echo "$(GREEN) $(NAME_BONUS) ✔︎ $(DEF_COLOUR)"
	@echo "$(GREEN) Usage: ./$(NAME_BONUS) ./maps/valid/'select a map' ✔︎ $(DEF_COLOUR)"

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@$(MAKE) clean -C $(MLX_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@echo "$(GREEN)Object files removed!$(DEF_COLOUR)"
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -rf $(MLX_DIR)
	@echo "$(NAME) removed!"

re: fclean all
.PHONY: clean fclean re all
