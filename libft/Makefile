# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/12 18:07:46 by dbouron           #+#    #+#              #
#    Updated: 2021/11/12 18:40:24 by dbouron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft

SRC = *.c

all : $(NAME)

$(NAME) :
	gcc -Wall -Werror -Wextra -o $(NAME) $(SRC)

clean :
	/bin/rm -rf *.o

fclean : clean
	/bin/rm -rf $(NAME)

re : fclean all