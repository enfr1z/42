# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 18:03:01 by vsanta            #+#    #+#              #
#    Updated: 2019/05/02 19:24:48 by vsanta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INCLUDES = includes/

SRC=ft_memalloc.c ft_strdup.c ft_memccpy.c ft_strequ.c ft_memchr.c \
	ft_striter.c ft_memcmp.c ft_striteri.c ft_atoi.c ft_memcpy.c \
	ft_strjoin.c ft_bzero.c ft_memdel.c ft_strlcat.c ft_delint.c \
	ft_memmove.c ft_strlen.c ft_digitcount.c ft_memrcpy.c ft_strmap.c \
	ft_isalnum.c ft_memset.c ft_strmapi.c ft_isalpha.c ft_putchar.c \
	ft_strncat.c ft_isascii.c ft_putchar_fd.c ft_strncmp.c ft_isdigit.c \
	ft_putendl.c ft_strncpy.c ft_islower.c ft_putendl_fd.c ft_strnequ.c \
	ft_isprint.c ft_putnbr.c ft_strnew.c ft_isspace.c ft_putnbr_fd.c \
	ft_strnstr.c ft_isupper.c ft_putstr.c ft_strrchr.c ft_itoa.c \
	ft_putstr_fd.c ft_strsplit.c ft_lstadd.c ft_skipspace.c ft_strstr.c \
	ft_lstdel.c ft_strcat.c ft_strsub.c ft_lstdel_content.c ft_strchr.c \
	ft_strtrim.c ft_lstdelone.c ft_strclr.c ft_tolower.c ft_lstiter.c \
	ft_strcmp.c ft_toupper.c ft_lstmap.c ft_strcpy.c ft_lstnew.c \
	ft_strdel.c ft_sqrt.c

OBJECTS=$(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c -I $(INCLUDES) $(SRC)
	@ar rc $(NAME) $(OBJECTS)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
