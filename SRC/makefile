# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: arommers <arommers@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/14 11:40:10 by arommers      #+#    #+#                  #
#    Updated: 2023/02/02 14:34:33 by arommers      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long.a
SRC =  so_long.c make_map.c make_images.c coordinates.c moves.c link.c
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