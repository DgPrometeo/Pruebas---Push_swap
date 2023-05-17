# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 17:10:42 by danielga          #+#    #+#              #
#    Updated: 2023/05/17 19:40:31 by danielga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

SRC = push_swap.c 

OBJECTS = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C ./libft

$(NAME): $(LIBFT) $(OBJECTS)
	ar -crs $(NAME) $(OBJECTS) ./libft/libft.a

clean:
	rm -rf $(OBJECTS)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make -C fclean ./libft

re: fclean all

.PHONY : all clean fclean re

