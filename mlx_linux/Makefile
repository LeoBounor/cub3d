##
## Makefile for MiniLibX in /home/boulon/work/c/raytraceur/minilibx
## 
## Made by Olivier Crouzet
## Login   <ol@epitech.net>
## 
## Started on  Tue Oct  5 15:56:43 2004 Olivier Crouzet
## Last update Tue May 15 15:44:41 2007 Olivier Crouzet
##

## Please use configure script

# COLORS
ERASE := \033[2K\033[1A\r
CLEAN_TEXT := \033[36m
INFO_TEXT := \033[35m
GOOD_TEXT := \033[32m
BAD_TEXT := \033[31m
RESET := \033[0m

all	: do_configure
	echo "\r$(GOOD_TEXT)✅ Making minilibx$(RESET)"

do_configure	:
	printf "$(GOOD_TEXT)⏳ Making minilibx$(BAD_TEXT)"
	./configure > /dev/null 2> /dev/null

clean	:
	./configure clean

re	: clean all
