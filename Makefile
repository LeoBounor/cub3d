# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 15:11:58 by jcollon           #+#    #+#              #
#    Updated: 2023/07/11 16:41:31 by jcollon          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash
NAME := cub3D
CC := cc

SRC_FILE := main.c
OBJ = $(addprefix $(DIR_OBJ)/, $(SRC_FILE:.c=.o))

DIR_OBJ := .obj
LIBFT := libft/libft.a
PARSING := parsing/parsing.a
MINILIBX := minilibx/libmlx.a
EXEC := src/exec/exec.a
UTILS := src/utils/utils.a
FLAGS := -g -MMD -MP -Wall -Wextra -Werror
DEBUG := $(FLAGS)
FLAGS += -O3

ifeq ($(shell uname -s) , Linux)
	MLX_FLAGS := -lXext -lX11 -lm
else
	MLX_FLAGS := -lmlx -L ./minilibx -lm -framework OpenGL -framework AppKit
endif
INCLUDE := -I./includes -I./minilibx -I./libft

RELINK := Makefile $(LIBFT) $(MINILIBX) $(EXEC) $(PARSING) $(UTILS)

# COLORS
ERASE := \033[2K\033[1A\r
CLEAN_TEXT := \033[36m
INFO_TEXT := \033[35m
GOOD_TEXT := \033[32m
BAD_TEXT := \033[31m
RESET := \033[0m


all: $(NAME)
bonus: all
$(NAME): $(MINILIBX) $(LIBFT) $(UTILS) $(PARSING) $(EXEC) $(DIR_OBJ) $(OBJ)
	echo -e "$(GOOD_TEXT)✅ Making $(NAME)$(BAD_TEXT)"
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(EXEC) $(PARSING) $(UTILS) $(LIBFT) $(MINILIBX) $(MLX_FLAGS) $(INCLUDE)
	printf "$(RESET)"
debug: FORCE
	touch Makefile $(LIBFT) $(EXEC) $(PARSING) $(UTILS)	
	$(MAKE) -s FLAGS="$(DEBUG)" all

$(DIR_OBJ):
	mkdir -p $@

$(LIBFT): FORCE
	$(MAKE) -sC libft FLAGS="$(FLAGS)"
$(PARSING): FORCE
	+$(MAKE) -sC parsing FLAGS="$(FLAGS)"
$(EXEC): FORCE
	+$(MAKE) -sC src/exec FLAGS="$(FLAGS)"
$(UTILS): FORCE
	+$(MAKE) -sC src/utils FLAGS="$(FLAGS)"
$(MINILIBX):
	if [[ " $(shell uname -s)" = *" Linux"* ]]; then \
		ln -nsf mlx_linux minilibx; \
	else \
		ln -nsf mlx_mac minilibx; \
	fi
	+$(MAKE) -j1 -sC minilibx

$(DIR_OBJ)/%.o: src/%.c $(RELINK)
	echo -e "$(GOOD_TEXT)⏳ Making $(NAME)"
	printf "$(INFO_TEXT) ➥ Making $(RESET)$< $(BAD_TEXT)"
	$(CC) $(FLAGS) -o $@ -c $< $(INCLUDE)
	printf "$(ERASE)"

clean:
	if [[ " $(MAKECMDGOALS)" = *" $@"* ]]; then \
		echo -e "$(CLEAN_TEXT)🧹 Cleaning minilibx$(RESET)"; \
		$(MAKE) -sC minilibx clean > /dev/null; \
		rm -rf minilibx; \
		$(MAKE) -sC libft clean; \
		$(MAKE) -sC parsing clean; \
		$(MAKE) -sC src/exec clean; \
		$(MAKE) -sC src/utils clean; \
		echo -e "$(CLEAN_TEXT)🧹 Cleaning $(NAME)$(RESET)"; \
	fi
	rm -rf $(DIR_OBJ)
fclean: clean
	echo -e "$(CLEAN_TEXT)🧹 FCleaning minilibx$(RESET)"
	-$(MAKE) -sC minilibx clean > /dev/null
	rm -rf minilibx
	-$(MAKE) -sC libft fclean
	-$(MAKE) -sC parsing fclean
	-$(MAKE) -sC src/exec fclean
	-$(MAKE) -sC src/utils fclean
	echo -e "$(CLEAN_TEXT)🧹 FCleaning $(NAME)$(RESET)"
	rm -f $(NAME)
re: fclean all

FORCE:
.PHONY: all bonus clean fclean re debug
.SILENT:
-include $(OBJ:.o=.d)
