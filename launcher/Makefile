# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tphung <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/19 18:37:57 by tphung            #+#    #+#              #
#    Updated: 2021/03/30 15:44:04 by tphung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -c
AR = ar
ARFLAGS = rcs

SRCS = main.c launcher.c
OBJ = $(SRCS:.c=.o)
NAME = go
LIBFT = libft.a
LIBFT_DIR = ../libft/
INCLUDES = ./

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(LIBFT_DIR)
		cp $(LIBFT_DIR)$(LIBFT) .
		$(CC) $(OBJ) $(LIBFT) -o $(NAME)

.c.o: 
		gcc $(FLAGS) $< -o $@

clean:
		rm -rf $(OBJ)
		make clean -C $(LIBFT_DIR)

fclean: clean
		rm -rf $(NAME)
		make fclean -C $(LIBFT_DIR)

re: fclean all
