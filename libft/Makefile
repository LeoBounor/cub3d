# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbounor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 13:20:56 by vducoulo          #+#    #+#              #
#    Updated: 2022/10/20 12:40:18 by lbounor          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
ft_tolower.c ft_toupper.c ft_strnstr.c ft_atoi.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_calloc.c ft_strdup.c ft_substr.c \
ft_strjoin.c ft_strtrim.c ft_putchar_fd.c ft_convert_base_printf_fd.c ft_printf.c ft_putnbr_unsigned_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_strmapi.c ft_split.c ft_striteri.c \
get_next_line_bonus.c get_next_line_utils_bonus.c


SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
ft_lstclear.c ft_lstiter.c ft_lstmap.c


OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CC = gcc
RM = rm -f

FLAGS = -Wall -Wextra -Werror
.c.o: Makefile
	${CC} ${FLAGS} -I includes -c $< -o ${<:.c=.o}

$(NAME): Makefile ${OBJS}
	ar rcs ${NAME} ${OBJS} 

all: Makefile ${NAME}

bonus: ${OBJS} ${OBJS_BONUS} Makefile
	ar rcs ${NAME} ${OBJS} ${OBJS_BONUS}

clean:
	${RM} ${OBJS}
	${RM} ${OBJS_BONUS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all
         
.PHONY: all clean fclean re