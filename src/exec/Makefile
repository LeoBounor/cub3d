# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbounor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 14:43:17 by jcollon           #+#    #+#              #
#    Updated: 2023/06/15 12:30:37 by lbounor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash
NAME := exec.a

SRC_FILE := player_movements_rotation.c \
			print_floor_ceiling.c \
			raycasting_looking.c \
			player_movements.c \
			raycasting_utils.c \
			main_execution.c \
			key_handler.c \
			draw_walls.c \
			game_utils.c \
			raycasting.c \
			game_init.c \
			game_stop.c \
			mlx_utils.c \
			textures.c
OBJ_FILE := $(SRC_FILE:.c=.o)
OBJ = $(addprefix $(DIR_OBJ)/, $(OBJ_FILE))

DIR_OBJ := .obj
FLAGS := -g3 -MMD -MP -Wall -Wextra -O3 #-Werror

INCLUDE := -I. -I../../includes -I../libft -I../../parsing -I../../minilibx
RELINK := Makefile ../../libft/libft.a ../../parsing/parsing.a ../../minilibx/libmlx.a

# COLORS
GOOD_TEXT := \033[32m
BAD_TEXT := \033[31m
CLEAN_TEXT := \033[36m
INFO_TEXT := \033[35m
ERASE := \033[2K\r\033[1A
RESET := \033[0m



all: $(NAME)
$(NAME): $(DIR_OBJ) $(OBJ)
	echo -e "$(GOOD_TEXT)✅ Making $(NAME:.a=)$(BAD_TEXT)"
	ar rc $(NAME) $(OBJ)
	printf "$(RESET)"



$(DIR_OBJ):
	mkdir -p $@

$(DIR_OBJ)/%.o: %.c $(RELINK)
	echo -e "$(GOOD_TEXT)⏳ Making $(NAME:.a=)"
	printf "$(INFO_TEXT) ➥ Making $(RESET)$@ $(BAD_TEXT)"
	$(CC) $(FLAGS) -o $@ -c $< $(INCLUDE)
	if [[ "$(MAKEFLAGS)" = *"--jobserver-auth"* ]]; then \
		printf "\n"; \
	else \
		printf "$(ERASE)"; \
	fi

clean:
	echo -e "$(CLEAN_TEXT)🧹 $(subst f,F,$(subst c,C,$(MAKECMDGOALS)))ing $(NAME:.a=)$(BAD_TEXT)"
	rm -rf $(DIR_OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
.SILENT:
-include $(OBJ:.o=.d)