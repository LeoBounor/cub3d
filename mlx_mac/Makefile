#
#

# COLORS
ERASE := \033[2K\033[1A\r
CLEAN_TEXT := \033[36m
INFO_TEXT := \033[35m
GOOD_TEXT := \033[32m
BAD_TEXT := \033[31m
RESET := \033[0m

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2
DIR_OBJ := .obj

all: $(NOM)
	echo "\r$(GOOD_TEXT)✅ Making minilibx$(RESET)"

$(NOM):	$(DIR_OBJ) $(OBJ)
	ar -r $(NOM) $(OBJ) 2> /dev/null
	ranlib $(NOM)

$(DIR_OBJ):
	mkdir -p $@

$(DIR_OBJ)/%.o: %.c
	echo "$(GOOD_TEXT)⏳ Making $(NOM:.a=)"
	printf "$(INFO_TEXT) ➥ Making $(RESET)$@$(BAD_TEXT)"
	$(CC) $(CFLAGS) $(FLAGS) -o $@ -c $< $(INCLUDE) 2> /dev/null
	printf "$(ERASE)"
$(DIR_OBJ)/%.o: %.m
	echo "$(GOOD_TEXT)⏳ Making $(NAME:.a=)"
	printf "$(INFO_TEXT) ➥ Making $(RESET)$@$(BAD_TEXT)"
	$(CC) $(CFLAGS) $(FLAGS) -o $@ -c $< $(INCLUDE) 2> /dev/null
	printf "$(ERASE)"

clean:
	rm -f $(NOM) $(OBJ) *~
	rm -f mlx_app
	rm -rf $(DIR_OBJ)

re: clean all
.SILENT:
PHONY: all clean re
