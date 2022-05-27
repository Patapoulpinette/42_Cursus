# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 14:53:19 by dbouron           #+#    #+#              #
#    Updated: 2022/05/27 15:32:23 by dbouron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fdf

# **************************************************************************** #
#                               FILES and PATHS                                #
# **************************************************************************** #

HEADFILE = fdf.h

MINILIBX = ./minilibx_macos
#MINILIBX_EXEC = ./minilibx_macos/libmlx.a

SRCS =	 main.c parsing.c len.c utils.c split.c utils_split.c graphical_part.c free.c algorithm.c

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

all : compile_minilibx $(NAME)

%.o: %.c $(HEADFILE) Makefile
	gcc -Wall -Wextra -Werror -o $@ -c $<
	@printf "\r$(LIGHT_GRAY)Loading...$(NO_COLOR)"

$(NAME) : $(OBJS) $(HEADFILE)
	gcc -Wall -Wextra -Werror -fsanitize=address -g3 -o $(NAME) $(SRCS) -I/usr/local/include -L minilibx_macos -lmlx -framework OpenGL -framework AppKit
	@printf "\r$(LIGHT_GREEN)➞$(NO_COLOR) Compiled $(LIGHT_GREEN)✔$(NO_COLOR)\n"

compile_minilibx :
	@make -C $(MINILIBX)

clean :
	rm -rf $(OBJS)
	@make clean -C $(MINILIBX)
	@printf "\r$(LIGHT_BLUE)➞$(NO_COLOR) Cleaned $(LIGHT_BLUE)✔$(NO_COLOR)\n"

fclean : clean
	rm -rf $(NAME)
	@make clean -C $(MINILIBX)

re : fclean all

.PHONY: all compile_minilibx clean fclean re