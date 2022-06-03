# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 14:53:19 by dbouron           #+#    #+#              #
#    Updated: 2022/06/03 10:06:30 by dbouron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

# **************************************************************************** #
#                               FILES and PATHS                                #
# **************************************************************************** #

HEADFILE =	fdf.h \
			./GNL/get_next_line.h \
			./libft/libft.h

MINILIBX = ./minilibx_macos
#MINILIBX_EXEC = ./minilibx_macos/libmlx.a

LIBFT = ./libft
LIBFT_EXEC = ./libft/libft.a

SRCS =	main.c \
		parsing.c utils.c \
		graphical_part.c drawing_part.c algorithm.c \
		free.c \
		bonus.c \
		./GNL/get_next_line.c \
		./GNL/get_next_line_utils.c

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

all : compile_minilibx compile_libft $(NAME)

%.o: %.c $(HEADFILE) Makefile
	gcc -Wall -Wextra -Werror -o $@ -c $<
	@printf "\r$(LIGHT_GRAY)Loading...$(NO_COLOR)"

$(NAME) : $(OBJS) $(HEADFILE) $(LIBFT_EXEC)
	gcc -Wall -Wextra -Werror -o $(NAME) $(LIBFT_EXEC) $(SRCS) -I/usr/local/include -L minilibx_macos -lmlx -framework OpenGL -framework AppKit
	@printf "\r$(LIGHT_GREEN)➞$(NO_COLOR) Compiled $(LIGHT_GREEN)✔$(NO_COLOR)\n"

compile_minilibx :
	@make -C $(MINILIBX)

compile_libft :
	@make -C $(LIBFT)

clean :
	rm -rf $(OBJS)
	@make clean -C $(MINILIBX)
	@make clean -C $(LIBFT)
	@printf "\r$(LIGHT_BLUE)➞$(NO_COLOR) Cleaned $(LIGHT_BLUE)✔$(NO_COLOR)\n"

fclean : clean
	rm -rf $(NAME)
	@make clean -C $(MINILIBX)
	@make fclean -C $(LIBFT)

re : fclean all

.PHONY: all compile_minilibx compile_libft clean fclean re