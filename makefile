# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: arommers <arommers@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/13 13:44:52 by arommers      #+#    #+#                  #
#    Updated: 2023/04/11 10:26:47 by adri          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

PROJECT = so long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX42FLAGS = -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
NAME = so_long
LIBFT = ./libft/libft.a
MLX42 = ./MLX42/libmlx42.a
INCLUDE = -I./include
SRC =  ./src/so_long.c ./src/render_map.c		\
		./src/parse_map.c ./src/moves.c			\
		./src/load_link.c ./src/load_images.c	\
		./src/initialize_structs.c				\
		./src/get_coordinates.c					\
		./src/directions.c						\
		./src/map_check_1.c						\
		./src/map_check_2.c						\
		./src/miscellaneous.c					\
		./src/path_checker.c					\
		./src/enemy.c							\
		./src/screen_string.c
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

BOLD    := \033[1m./SRC/
RED     := \033[31;1m
GREEN   := \033[32;1m
YELLOW  := \033[33;1m
BLUE    := \033[34;1m
MAGENTA := \033[35;1m
CYAN    := \033[36;1m
WHITE   := \033[37;1m
RESET	= \x1b[0m

all: $(NAME)

$(NAME): $(LIBFT) $(MLX42) $(OBJ)	
	@echo "Compiled with $(BLUE)$(CFLAGS)$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX42) $(MLX42FLAGS)
	@echo "$(CYAN)-------------------------------------------"
	@echo "	$(NAME) = NOW READY FOR USE!"
	@echo "-------------------------------------------$(RESET)"

$(LIBFT):
	@$(MAKE) -C ./Libft

$(MLX42):
	@$(MAKE) -C ./MLX42

$(OBJ_DIR)/%.o: ./src/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "Compiled ✅ $(CYAN) $^ $(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^

clean:
	@$(MAKE) clean -C ./Libft
	@$(MAKE) clean -C ./MLX42
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C ./Libft
	@$(MAKE) fclean -C ./MLX42
	@rm -f $(NAME)
	@echo "$(GREEN) $(PROJECT) $(RESET) Cleansed ✅"

re: fclean all

.PHONY: all clean fclean re
