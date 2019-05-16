# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/14 17:23:28 by pdiedra           #+#    #+#              #
#    Updated: 2019/05/14 21:19:13 by vsanta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= fdf

SRC_PATH		= ./src/
INCLUDE_PATH	= ./includes
LIBFT_PATH		= ./libft

SRC_NAME		= color.c draw.c events.c main.c projections.c put_window.c \
					reader.c rotation.c

SRC				= $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ				= $(SRC_NAME:.c=.o)

FLAG			= -Wall -Wextra -Werror

MLX				= -L minilibx/ -lmlx -framework OpenGL -framework AppKit

CC				= gcc

all: $(NAME)

$(NAME): $(OBJ) lib
	@$(CC) $(OBJ) $(LIBFT_PATH)/libft.a -o $(NAME) $(FLAG) $(MLX)

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
