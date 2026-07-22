# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chehir <chehir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/14 17:05:49 by chehir            #+#    #+#              #
#    Updated: 2026/07/22 20:26:41 by chehir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror -g

NAME = wordle

LIB_DIR = ./customlib
INCLUDES_DIR = ./includes
UTILS_DIR = ./utils

LIB = $(LIB_DIR)/customlib.a


SOURCES = \
		wordle.c								\
		$(UTILS_DIR)/wordle_display_utils.c		\
		$(UTILS_DIR)/wordle_verif_utils.c		\
		$(UTILS_DIR)/wordle_setup_utils.c		\
		$(UTILS_DIR)/wordle_game_utils.c

OBJECTS = $(SOURCES:.c=.o)

RM = rm -rf


%.o: %.c $(LIB)
		@$(CC) $(FLAGS) -c $< -o $@


all: $(LIB) $(NAME)

$(LIB):
		@make -C $(LIB_DIR)

$(NAME): $(OBJECTS) $(LIB)
		@$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) $(LIB)
		@echo "Wordle executable created"

clean:
		@$(RM) $(OBJECTS)
		make clean -C customlib
		@echo "Removed .o files"

fclean: clean
		@$(RM) $(NAME)
		make fclean -C $(LIB_DIR)
		@echo "Removed executable file"

re: fclean all

.PHONY: all clean fclean re
