# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 09:09:46 by msavelie          #+#    #+#              #
#    Updated: 2024/05/15 09:09:48 by msavelie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = \
	ft_printf.c \
	ft_putstr.c \
	ft_putchar.c \
	ft_print_hex.c 

OBJS = ${SRCS:.c=.o}

FLAGS = -Wall -Werror -Wextra
LIBFT_NAME = ./libft/libft.a
LIBFT_DIR = ./libft
RM = rm -rf
AR = ar -rcs
LIB = ranlib

.PHONY = all clean fclean re

all: ${LIBFT_NAME} ${NAME}

${LIBFT_NAME}:
	make -C ${LIBFT_DIR}

${NAME}: ${OBJS}
	cp ${LIBFT_DIR}/libft.a .
	mv libft.a ${NAME}
	${AR} ${NAME} ${OBJS}
	${LIB} ${NAME}

clean: 
	${RM} ${OBJS}
	make clean -C ${LIBFT_DIR}

fclean: clean
	${RM} ${NAME}
	make fclean -C ${LIBFT_DIR}

re: fclean all

%.o : %.c
	cc ${FLAGS} -c $< -o $@
