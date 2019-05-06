# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/01 16:23:15 by vsanta            #+#    #+#              #
#    Updated: 2019/05/01 16:48:35 by vsanta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= fillit

SRC_PATH		= ./src/
INCLUDE_PATH	= ./includes
LIBFT_PATH		= ./libft

SRC_NAME		= help.c main.c tetr.c valid.c map.c 

SRC				= $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ				= $(SRC_NAME:.c=.o)

FLAG			= -Wall -Wextra -Werror

CC				= gcc

all: $(NAME)

$(NAME): $(OBJ) lib
	@$(CC) $(OBJ) $(LIBFT_PATH)/libft.a -o $(NAME) $(FLAG)

$(OBJ):
	@$(CC) $(SRC) -c -I $(INCLUDE_PATH) -I $(LIBFT_PATH)/$(INCLUDE_PATH) $(FLAG)

lib:
	@make -C $(LIBFT_PATH)

relib:
	@make re -C $(LIBFT_PATH)

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all
