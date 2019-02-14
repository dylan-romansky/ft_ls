# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dromansk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/22 14:53:52 by dromansk          #+#    #+#              #
#    Updated: 2019/02/13 19:46:49 by dromansk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS = ./src/*.c ./src/struct_handling/*.c ./src/printing/*.c ./src/checks/*.c\
	   ./src/flags_and_path/*.c ./src/error/*.c

I = -I ./includes -I ./libft/includes

O = *.o

L = -L ./libft -lft

all: $(NAME)

$(NAME):
	make -C ./libft reclean
	gcc -Wall -Werror -Wextra -c $(I) $(SRCS)
	gcc -Wall -Werror -Wextra -o $(NAME) $(O) $(I) $(L)

clean:
	make -C ./libft clean
	rm -rf $(O)

fclean: clean
	make -C ./libft fclean
	rm -rf $(NAME)

re: fclean all

reclean: re
	make clean

test: reclean
	./$(NAME) -l
