# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: arommers <arommers@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/10 14:07:45 by arommers      #+#    #+#                  #
#    Updated: 2022/11/16 10:32:58 by arommers      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

PROJECT = Libft
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
		ft_strlen.c ft_strncmp.c
BSRC = ft_lstnew.c ft_lstadd_front.c 	\
		ft_lstsize.c ft_lstlast.c 		\
		ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c 		\
		ft_lstmap.c
OBJ = $(SRC:%.c=%.o)
BONUS = $(BSRC:%.c=%.o)

#colours
PINK	= \x1b[35m
RESET	= \x1b[0m
GREEN	= \x1b[32m
BLUE	= \x1b[34m

all: $(NAME)

start:
	@echo "$(PINK)------------------------------\n	Starting $(PROJECT)\n------------------------------$(RESET)"

$(NAME): start $(OBJ)
	@echo "Compiled with $(BLUE)$(CFLAGS)$(RESET)"
	@ar -rcs $@ $(OBJ)
	@echo "$(PINK)-------------------------------------------\n	$(NAME) = NOW READY FOR USE!\n-------------------------------------------$(RESET)"

%.o: %.c
	@echo "Compilation Done $(PINK) $^ $(RESET)"
	@$(CC) $(CFLAGS) -c -o $@ $^

bonus:	${OBJ} ${BONUS}
	@ar -rcs $(NAME) $(OBJ) $(BONUS)

clean:
	@echo "Cleaning Done $(GREEN) $@ $(PROJECT) $(RESET)"
	@rm -f $(OBJ) $(BONUS)
	

fclean: clean
	@echo "Cleaning Done $(GREEN) $@ $(PROJECT) $(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus