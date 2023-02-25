# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: arommers <arommers@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/13 13:44:52 by arommers      #+#    #+#                  #
#    Updated: 2023/02/25 14:31:46 by arommers      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

PROJECT = so long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX42FLAGS = -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
NAME = so_long
LIBFT = ./Libft/libft.a
MLX42 = ./MLX42/libmlx42.a
SRC =  ./SRC/so_long.c ./SRC/render_map.c		\
		./SRC/parse_map.c ./SRC/moves.c			\
		./SRC/load_link.c ./SRC/load_images.c	\
		./SRC/initialize_structs.c				\
		./SRC/get_coordinates.c					\
		./SRC/directions.c						\
		./SRC/map_check_1.c						\
		./SRC/map_check_2.c						\
		./SRC/miscellaneous.c					\
		./SRC/path_checker.c					\
		./SRC/enemy.c							\
		./SRC/screen_string.c
OBJ = $(SRC:.c=.o)

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

%.o: %.c
	@echo "Compiled ✅ $(CYAN) $^ $(RESET)"
	@$(CC) $(CFLAGS) -c -o $@ $^

clean:
	@$(MAKE) clean -C ./Libft
	@$(MAKE) clean -C ./MLX42
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) fclean -C ./Libft
	@$(MAKE) fclean -C ./MLX42
	@rm -f $(NAME)
	@echo "$(GREEN) $(PROJECT) $(RESET) Cleansed ✅"

re: fclean all

.PHONY: all clean fclean re
