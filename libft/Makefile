# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/12 18:07:46 by dbouron           #+#    #+#              #
#    Updated: 2022/01/28 20:03:09 by dbouron          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_bzero.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memcmp.c \
	ft_memmove.c ft_strchr.c ft_strlcat.c ft_strlen.c ft_strnstr.c \
	ft_tolower.c ft_atoi.c ft_calloc.c ft_isalpha.c ft_isdigit.c ft_memchr.c \
	ft_memcpy.c ft_memset.c ft_strdup.c ft_strlcpy.c ft_strncmp.c \
	ft_strrchr.c ft_toupper.c ft_substr.c ft_strjoin.c ft_strtrim.c \
	ft_split.c

OBJS = $(SRC:.c=.o)

%.o: %.c
	gcc -Wall -Werror -Wextra -o $@ -c $<


$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all