# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: arommers <arommers@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/10 14:07:45 by arommers      #+#    #+#                  #
#    Updated: 2023/03/21 10:21:47 by adri          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRC =  ft_split.c ft_itoa.c 			\
		ft_strmapi.c ft_striteri.c 		\
		ft_strtrim.c ft_strjoin.c 		\
		ft_substr.c ft_putnbr_fd.c 		\
		ft_putendl_fd.c ft_putstr_fd.c 	\
		ft_putchar_fd.c ft_strdup.c 	\
		ft_calloc.c ft_strnstr.c 		\
		ft_strlcat.c ft_memcmp.c 		\
		ft_atoi.c ft_strnstr.c 			\
		ft_memchr.c ft_memset.c 		\
		ft_memcpy.c ft_memmove.c 		\
		ft_strlcat.c ft_strlcpy.c 		\
		ft_bzero.c ft_isalpha.c 		\
		ft_toupper.c ft_isdigit.c 		\
		ft_tolower.c ft_isalnum.c 		\
		ft_strchr.c ft_isascii.c 		\
		ft_isprint.c ft_strrchr.c 		\
		ft_strlen.c ft_strncmp.c		\
		ft_lstnew.c ft_lstadd_front.c 	\
		ft_lstsize.c ft_lstlast.c 		\
		ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c 		\
		ft_lstmap.c get_next_line.c		\
		get_next_line_utils.c			\
		ft_printf.c ft_print_hex.c		\
		ft_print_ptr.c					\
		ft_print_various.c				\
		ft_print_unsigned.c

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

BLACK   := \033[30m
RED     := \033[31m
GREEN   := \033[32m
YELLOW  := \033[33m
BLUE 	:= \033[96m
MAGENTA := \033[38;5;206m
CYAN    := \033[36m
WHITE   := \033[37m
RESET   := \033[0m
BOLD    := \033[1m
DIM     := \033[2m
ITALIC  := \033[3m
UNDER   := \033[4m
BLINK   := \033[5m
REVERSE := \033[7m
HIDDEN  := \033[8m
PINK 	:= \033[35m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiled with $(BLUE)$(BOLD)$(CFLAGS)$(RESET)"
	@ar -rcs $@ $^
	@echo "$(PINK)$(BOLD)----------------------------------------"
	@echo "     $(NAME) = NOW READY FOR USE!"
	@echo "----------------------------------------$(RESET)"
	
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@echo "Compiled ✅ $(PINK) $(BOLD) $^ $(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^
	

clean:
	@rm -rf $(OBJ_DIR)
	@rm -f $(OBJ)
	
fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re