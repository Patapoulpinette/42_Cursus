# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 16:53:58 by dbouron           #+#    #+#              #
#    Updated: 2022/04/25 17:47:01 by dbouron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# **************************************************************************** #
#                               FILES and PATHS                                #
# **************************************************************************** #

HEADFILE = push_swap.h

SRCS = main.c utils.c algorithm.c swap.c push.c rotate.c reverse_rotate.c

# **************************************************************************** #
#                                    COLORS                                    #
# **************************************************************************** #

BLACK			=	\033[0;30m
RED				=	\033[0;31m
GREEN			=	\033[0;32m
ORANGE			=	\033[0;33m
BLUE			=	\033[0;34m
PURPLE			=	\033[0;35m
CYAN			=	\033[0;36m
LIGHT_GRAY		=	\033[0;37m
DARK_GRAY		=	\033[1;30m
LIGHT_RED		=	\033[1;31m
LIGHT_GREEN		=	\033[1;32m
YELLOW			=	\033[1;33m
LIGHT_BLUE		=	\033[1;34m
LIGHT_PURPLE	=	\033[1;35m
LIGHT_CYAN		=	\033[1;36m
WHITE			=	\033[1;37m
NO_COLOR		=	\033[0m

# **************************************************************************** #
#                              COMMANDS and RULES                              #
# **************************************************************************** #

.SILENT:

.DEFAULT_GOAL = all

OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o: %.c $(HEADFILE) Makefile
	gcc -Wall -Wextra -Werror -o $@ -c $<
	@printf "\rLoading..."

$(NAME) : $(OBJS) $(HEADFILE)
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRCS)
	@printf "\r$(LIGHT_GREEN)➞ Compiled [√]$(NO_COLOR)\n"

clean :
	rm -rf $(OBJS)
	@printf "\r$(LIGHT_BLUE)➞ Cleaned [√]$(NO_COLOR)\n"

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re