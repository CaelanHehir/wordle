# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chehir <chehir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/22 11:25:11 by chehir            #+#    #+#              #
#    Updated: 2026/07/22 20:40:47 by chehir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Use 'nm customlib.a' to check functions contained in the customlib library

CC = cc
FLAGS = -Wall -Wextra -Werror

NAME = customlib.a

SOURCES = \
	custom_bzero.c custom_calloc.c custom_display_functions.c			\
	custom_display_hex_functions.c custom_strchr.c custom_strlen.c		\
	custom_strncmp.c custom_tolower.c custom_toupper.c custom_atoi.c	\
	custom_isalpha.c custom_printf.c custom_putchar_fd.c				\
	custom_putnbr_fd.c custom_putstr_fd.c custom_read_next_line.c

OBJECTS = $(SOURCES:.c=.o)


%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

clean:
	@rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
