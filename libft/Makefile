# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chehir <chehir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/22 11:25:11 by chehir            #+#    #+#              #
#    Updated: 2025/11/23 15:18:51 by chehir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Use 'nm libft.a' to check functions contained in the libft library

CC = cc
FLAGS = -Wall -Wextra -Werror

NAME = libft.a

SOURCES = \
	ft_bzero.c ft_calloc.c ft_display_functions.c ft_display_hex_functions.c	\
	ft_strchr.c ft_strlen.c ft_strncmp.c ft_tolower.c ft_toupper.c ft_atoi.c	\
	ft_isalpha.c ft_printf.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c		\
	get_next_line.c

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
