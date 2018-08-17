# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/13 12:10:37 by ccliffor          #+#    #+#              #
#    Updated: 2018/08/17 13:04:52 by ccliffor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROGRAM #
NAME	= wolf3d
SRCDIR	= src/
SRCS	= $(SRCDIR)main.c $(SRCDIR)read.c $(SRCDIR)input.c $(SRCDIR)init.c \
			$(SRCDIR)update.c $(SRCDIR)render.c $(SRCDIR)map.c
LIBDIR	= lib/

## Compiling, lib, flags
INCLUDE	= include/
HEADER	= $(INCLUDE)wolf.h
WFLAGS	= -Wall -Werror -Wextra
CC		= clang
CFLAGS	= $(WFLAGS) -I $(INCLUDE) -L $(LIBDIR) -l SDL2-2.0.0 libft/libft.a

## Colours

COLOUR_CLEAR	= \033[0m
COLOUR_CYAN		= \033[01;36m
COLOUR_GREEN	= \033[00;32m

.PHONY: clean fclean re

# RULES #
all: $(NAME)

# Core program
$(NAME): $(SRCS) $(HEADER)
	@$(CC) $(CFLAGS) $(SRCS) -o $@
	@echo "$(COLOUR_CYAN)$(NAME) \t\t-- $(COLOUR_GREEN)EXECUTABLE COMPILED$(COLOUR_CLEAR)\n"

# General rules
clean:
	@rm -f $(NAME)
	@echo "$(COLOUR_CYAN)$(NAME) \t\t-- $(COLOUR_GREEN)EXECUTABLE REMOVED$(COLOUR_CLEAR)"

re: clean all

run: re
		@./wolf3d maps/01.wolf
