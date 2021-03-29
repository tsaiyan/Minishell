# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile2                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egums <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/30 11:45:53 by egums             #+#    #+#              #
#    Updated: 2020/11/06 15:45:41 by egums            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
NAME = libft.a
FLAG = -Wall -Wextra -Werror
SRC =	ft_memcmp.c ft_memchr.c ft_memcpy.c ft_memccpy.c ft_memmove.c	\
		ft_bzero.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c	\
		ft_isprint.c ft_toupper.c ft_isascii.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_strlcat.c ft_strlcpy.c ft_strnstr.c\
		ft_atoi.c ft_memset.c ft_calloc.c ft_strdup.c					\
																		\
		ft_substr.c	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c		\
		ft_itoa.c ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_putnbr_fd.c \
		ft_split.c
BSRC =	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c			\
	  	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c		\
		ft_lstmap.c
INC = -I ./
OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

all: $(NAME) $(SRC)

$(NAME): $(OBJ) $(BOBJ) libft.h
ifdef $(BONUS_RULE)
	@ar rcs $(NAME) $(OBJ) $(BOBJ)
else
	@ar rcs $(NAME) $(OBJ)
endif

bonus: RULE all

RULE: BONUS_RULE ?= TRUE

%.o: %.c libft.h
	@$(CC) -c $(FLAG) $< $(INC)

.PHONY: RULE bonus all clean fclean re

clean:
	@rm -f $(OBJ) $(BOBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
