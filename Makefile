# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 17:10:42 by danielga          #+#    #+#              #
#    Updated: 2023/10/12 11:32:54 by danielga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c ft_check.c ft_index.c ft_utils.c ft_inserts.c ft_index.c ft_push.c ft_swap.c

OBJECTS = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror
RM	=	rm -f
AR	=	ar -rcs

LIBFT	=	./libft/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C ./libft


$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJECTS) -o $(NAME)

clean:
	$(RM) $(OBJECTS)
	make clean -C ./libft

fclean: clean
	$(RM) $(NAME)
	make -C fclean ./libft

re: fclean all

.PHONY : all clean fclean re

