# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luatshem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 11:10:43 by luatshem          #+#    #+#              #
#    Updated: 2023/07/06 11:10:49 by luatshem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract_ol

SRC =	main.c			\
		julia.c			\
		newton.c		\
		utils_1.c		\
		utils_2.c		\
		utils_3.c		\
		mandelbrot.c	

OBJ = $(SRC:.c=.o)

RM = rm -rf

CC = gcc

CFLAGS = -Wall -Werror -Wextra

FT_PRINTF = printf/libftprintf.a

all : printfcomp $(NAME)

printfcomp : 
		make -C printf

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(FT_PRINTF) $(OBJ) -Imlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
	$(RM) $(OBJ)
	make -C printf clean

fclean : clean
	$(RM) $(NAME)
	make -C printf fclean

re : fclean all

.PHONY: re, all, fclean, clean
