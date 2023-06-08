# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 17:10:42 by danielga          #+#    #+#              #
#    Updated: 2023/05/23 18:46:20 by danielga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c 

OBJECTS = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror
RM	=	rm -f
AR	=	ar -rcs

LIBFT	=	./libft/libft.a
PRINTF	=	./ft_printf/libftprintf.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C ./libft

$(PRINTF):
	make -C ./ft_printf

$(NAME): $(LIBFT) $(OBJECTS) | $(PRINTF) $(OBJECTS)
	$(CC) $(CFLAGS) $(LIBFT) $(PRINTF) $(OBJECTS) -o $(NAME)

clean:
	$(RM) $(OBJECTS)
	make clean -C ./libft
	make clean -C ./ft_printf

fclean: clean
	$(RM) $(NAME)
	make -C fclean ./libft
	make -C fclean ./ft_printf

re: fclean all

.PHONY : all clean fclean re

