# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: arommers <arommers@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/13 13:44:52 by arommers      #+#    #+#                  #
#    Updated: 2023/02/03 11:08:16 by arommers      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

PROJECT = So Long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
MLX42FLAGS = -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
NAME = so_long
LIBFT = ./Libft/libft.a
MLX42 = ./MLX42/libmlx42.a
SO_LONG = ./SRC/so_long.a
SRC = ./SRC/so_long.c ./SRC/make_map.c \
	./SRC/make_images.c ./SRC/coordinates.c \
	./SRC/moves.c ./SRC/link.c
OBJ = $(SRC:.c=.o)

BOLD    := \033[1m
BLACK   := \033[30;1m
RED     := \033[31;1m
GREEN   := \033[32;1m
YELLOW  := \033[33;1m
BLUE    := \033[34;1m
MAGENTA := \033[35;1m
CYAN    := \033[36;1m
WHITE   := \033[37;1m
RESET	= \x1b[0m

all: $(NAME)

$(NAME): $(LIBFT) $(MLX42) start $(SO_LONG) 
	@echo "Compiled with $(BLUE)$(CFLAGS)$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(LIBFT) $(SO_LONG) $(MLX42) $(MLX42FLAGS)
	@echo "$(CYAN)-------------------------------------------\n     $(NAME) = NOW READY FOR USE!\n-------------------------------------------$(RESET)"

$(LIBFT):
	@$(MAKE) -C ./Libft

$(MLX42):
	@$(MAKE) -C ./MLX42

$(SO_LONG): $(SRC) $(OBJ)
	@$(MAKE) -C ./SRC

start:
	@echo "$(CYAN)------------------------------\n	Starting $(PROJECT)\n------------------------------$(RESET)"

clean:
	@$(MAKE) clean -C ./Libft
	@$(MAKE) clean -C ./MLX42
	@$(MAKE) clean -C ./SRC
	@rm -f $(OBJ)
	@echo "Cleaning Done $(GREEN) $@ $(PROJECT) $(RESET)"

fclean: clean
	@$(MAKE) fclean -C ./Libft
	@$(MAKE) fclean -C ./MLX42
	@$(MAKE) fclean -C ./SRC
	@rm -f $(NAME)
	@echo "Cleaning Done $(GREEN) $@ $(PROJECT) $(RESET)"

re: fclean all

.PHONY: all clean fclean re

run: all
	./so_long Maps/map1.ber