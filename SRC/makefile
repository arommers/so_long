# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: arommers <arommers@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/14 11:40:10 by arommers      #+#    #+#                  #
#    Updated: 2023/02/18 15:04:56 by arommers      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long.a
SRC =  so_long.c render_map.c		\
		parse_map.c moves.c			\
		load_link.c load_images.c	\
		initialize_structs.c		\
		get_coordinates.c			\
		directions.c				\
		map_check_1.c				\
		map_check_2.c				\
		miscellaneous.c				\
		path_checker.c				\
		enemy.c						\
		screen_string.c
OBJ = $(SRC:.c=.o)

MAGENTA := \033[35;1m
BOLD    := \033[1m
CYAN    := \033[36;1m
WHITE   := \033[37;1m
RESET	= \x1b[0m

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $@ $^
	@echo "Compilation Done $(BOLD) $(CYAN)$(SRC) $(RESET)"
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re