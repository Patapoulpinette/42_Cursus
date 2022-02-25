# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/25 18:24:38 by dbouron           #+#    #+#              #
#    Updated: 2022/02/25 18:26:30 by dbouron          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADFILE = printf.h

SRC = ft_printf.c

OBJS = $(SRC:.c=.o)

%.o: %.c $(HEADFILE)
	gcc -Wall -Werror -Wextra -o $@ -c $<

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all