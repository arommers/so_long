# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: arommers <arommers@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/10 14:07:45 by arommers      #+#    #+#                  #
<<<<<<< HEAD
#    Updated: 2023/02/20 16:29:06 by arommers      ########   odam.nl          #
=======
#    Updated: 2023/02/20 10:52:21 by arommers      ########   odam.nl          #
>>>>>>> ce9089f755662a2c9e016060319f8e3328477564
#                                                                              #
# **************************************************************************** #

PROJECT = So Long
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

OBJ = $(SRC:%.c=%.o)

#colours
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

start:
	@echo "$(CYAN)-------------------------------------------"
	@echo "	     Starting $(PROJECT)"
	@echo "-------------------------------------------$(RESET)"
	
$(NAME): start $(OBJ)
	@echo "Compiled with $(BLUE)$(CFLAGS)$(RESET)"
	@ar -rcs $@ $(OBJ)
	@echo "$(MAGENTA)-------------------------------------------"
	@echo "	$(NAME) = NOW READY FOR USE!"
	@echo "-------------------------------------------$(RESET)"
	
%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $^
	@echo "Compiled ✅ $(MAGENTA) $^ $(RESET)"

clean:
	@rm -f $(OBJ)
	

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re