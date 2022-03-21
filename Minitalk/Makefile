# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 18:47:31 by dbouron           #+#    #+#              #
#    Updated: 2022/03/21 20:08:23 by dbouron          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME_S = server
NAME_C = client

# **************************************************************************** #
#                               FILES and PATHS                                #
# **************************************************************************** #

HEADFILE =		minitalk.h

SRC_PRINTF =		./ft_printf

SRCS_S =			server.c

SRCS_C =			client.c

SRCS =				minitalk_utils.c

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

OBJS_S = $(SRCS_S:.c=.o)

OBJS_C = $(SRCS_C:.c=.o)

OBJS =$(SRCS:.c=.o)

%.o: $(SRCS_S) $(SRCS_C) $(SRCS) $(HEADFILES)
	gcc -Wall -Werror -Wextra -o $@ -c $<
	@printf "\033[2K\r$(CYAN)Lowding...$(RESET)"

$(NAME_S) : $(OBJS_S) $(OBJS)
	ar rcs $(NAME_S) $(OBJS_S) $(OBJS)
	@printf "\033[2K\r$(LIGHT_GREEN)--> compiled [√]\n"

$(NAME_C) : $(OBJS_C) $(OBJS)
	ar rcs $(NAME_C) $(OBJS_C) $(OBJS)
	@printf "\033[2K\r$(LIGHT_GREEN)--> compiled [√]\n"
	
all : compil $(NAME_S) $(NAME_C)

compil :
	@make -C $(SRC_PRINTF)

server : compil $(NAME_S)

client : compil $(NAME_C)

clean :
	rm -rf $(OBJS_S) $(OBJS_C) $(OBJS)
	@make clean -C $(SRC_PRINTF)
	@printf "\033[2K\r$(LIGHT_BLUE)--> cleaned\n"

fclean : clean
	rm -rf $(NAME_S) $(NAME_C)
	@make fclean -C $(SRC_PRINTF)

re : fclean all

.PHONY: all server client clean fclean re