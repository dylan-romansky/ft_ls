# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dromansk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/22 14:53:52 by dromansk          #+#    #+#              #
#    Updated: 2019/02/05 15:32:00 by dromansk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ./src/printf/*.c ./src/printf/conversion/*.c \
./src/printf/parsing_and_handling/*.c ./src/printf/flags/*.c \
./src/printf/formatting_and_helpers/*.c ./src/libft/*.c \
./src/printf/colours/*.c

I = -I ./includes

O = *.o

L = -L ./ -lft

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra $(I) $(SRCS) -c
	ar rcs $(NAME) $(O)
	ranlib $(NAME)

clean:
	rm -rf $(O)

fclean: clean
	rm -rf $(NAME)

re: fclean all

reclean: re
	make clean

test: reclean
	gcc main.c $(I) $(L)
	./ftest

run: clean
	gcc main.c $(I) $(L)
	./ftest
