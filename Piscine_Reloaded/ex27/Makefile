# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdiedra <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 16:55:29 by pdiedra           #+#    #+#              #
#    Updated: 2019/04/02 17:58:04 by pdiedra          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

HEADER = ./includes/

SRCS = ./project/srcs/ft_putstr.c ./project/main.c ./project/display_file.c

OBJ = ft_putstr.o

FLAG = -Wall -Wextra -Werror

all: libft main

libft:
	gcc $(FLAG) -c $(SRCS) -I $(HEADER)
	ar rc libft.a $(OBJ)

main:
	gcc main.o display_file.o libft.a -o $(NAME) $(FLAG)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f libft.a ft_display_file

re: fclean all
