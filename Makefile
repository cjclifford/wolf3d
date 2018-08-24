# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/13 12:10:37 by ccliffor          #+#    #+#              #
#    Updated: 2018/08/24 11:49:52 by ccliffor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROGRAM #
NAME		= wolf3d
SOURCES		= main.c read.c input.c init.c update.c render.c
SRCS		= $(SOURCES:%=src/%)
SDL2_CONFIG	= SDL2/bin/sdl2-config
SDL2_SRCS	= SDL2-2.0.8
SDL2_TARBALL= $(SDL2_SRCS).tar.gz

## Compiling, lib, flags
INCLUDE	= include/
HEADERS	= $(INCLUDE)wolf.h
WFLAGS	= -Wall -Werror -Wextra
CC		= clang
CFLAGS	= $(WFLAGS) -I $(INCLUDE) libft/libft.a

## Colours

COLOUR_CLEAR	= \033[0m
COLOUR_CYAN		= \033[01;36m
COLOUR_GREEN	= \033[00;32m

.PHONY: clean fclean re run

# RULES #
all: $(NAME)

# Core program
$(SDL2_TARBALL):
	git clone https://github.com/davidsiaw/SDL2.git $(SDL2_SRCS)

$(SDL2_SRCS): $(SDL2_TARBALL)
	tar -xvzf $(SDL2_SRCS).tar.gz

$(SDL2_CONFIG): $(SDL2_SRCS)
	cd $(SDL2_SRCS);\
	mkdir -p build;\
	cd build;\
	../configure --prefix=$(CURDIR)/SDL2;\
	make -j6; make install

$(NAME): $(SDL2_CONFIG) $(SRCS) $(HEADERS)
	@make -C libft
	@$(CC) $(CFLAGS) $(SRCS) -o $@ $(shell ./$(SDL2_CONFIG) --cflags --libs)
	@echo "$(COLOUR_CYAN)$(NAME) \t\t-- $(COLOUR_GREEN)EXECUTABLE COMPILED$(COLOUR_CLEAR)\n"

# General rules
clean:
	@rm -f $(NAME)
	@echo "$(COLOUR_CYAN)$(NAME) \t\t-- $(COLOUR_GREEN)EXECUTABLE REMOVED$(COLOUR_CLEAR)"

re: clean all

run: re
		@./wolf3d maps/01.wolf
