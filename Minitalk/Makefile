# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 11:25:39 by dbouron           #+#    #+#              #
#    Updated: 2022/04/04 17:19:28 by dbouron          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
BONUSS = server_bonus
BONUSC = client_bonus

# **************************************************************************** #
#                               FILES and PATHS                                #
# **************************************************************************** #

HEADFILE =		minitalk.h

HEADFILE_BONUS = minitalk_bonus.h

PRINTF =		./ft_printf
PRINTF_LIB =	./ft_printf/libftprintf.a

SRCS_SERVER =	server.c minitalk_utils.c

SRCS_CLIENT =	client.c minitalk_utils.c

SRCS_SERVER_BONUS =	server_bonus.c minitalk_utils_bonus.c

SRCS_CLIENT_BONUS =	client_bonus.c minitalk_utils_bonus.c

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

OBJS_SERVER = $(SRCS_SERVER:.c=.o)

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)

OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

all : printf_lib Makefile $(SERVER) $(CLIENT)

%.o: %.c $(HEADFILES) $(HEADFILE_BONUS)
	gcc -Wall -Wextra -Werror -o $@ -c $<
	@printf "\033[2K\r$(CYAN)Loading...$(RESET)"

$(SERVER) : $(OBJS_SERVER) $(HEADFILE) $(PRINTF_LIB)
	gcc -Wall -Wextra -Werror -o $(SERVER) $(SRCS_SERVER) -L./ft_printf -l ftprintf
	@printf "\033[2K\r$(LIGHT_GREEN)--> Server compiled [√]\n"

$(CLIENT) : $(OBJS_CLIENT) $(HEADFILE) $(PRINTF_LIB)
	gcc -Wall -Wextra -Werror -o $(CLIENT) $(SRCS_CLIENT) -L./ft_printf -l ftprintf
	@printf "\033[2K\r$(LIGHT_GREEN)--> Client compiled [√]\n"
	
printf_lib :
	@make -C $(PRINTF)

bonus : ${BONUSS} ${BONUSC}

${BONUSS} : $(OBJS_SERVER_BONUS) $(HEADFILE_BONUS) $(PRINTF_LIB)
	gcc -Wall -Wextra -Werror -o ${BONUSS} $(SRCS_SERVER_BONUS) -L./ft_printf -l ftprintf
	@printf "\033[2K\r$(LIGHT_GREEN)--> Bonus : server compiled [√]\n"

${BONUSC} : $(OBJS_CLIENT_BONUS) $(HEADFILE_BONUS) $(PRINTF_LIB)
	gcc -Wall -Wextra -Werror -o ${BONUSC} $(SRCS_CLIENT_BONUS) -L./ft_printf -l ftprintf
	@printf "\033[2K\r$(LIGHT_GREEN)--> Bonus : client compiled [√]\n"

clean :
	rm -rf $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)
	@make clean -C $(PRINTF)
	@printf "\033[2K\r$(LIGHT_BLUE)--> Cleaned\n"

fclean : clean
	rm -rf $(SERVER) $(CLIENT) ${BONUSS} ${BONUSC}
	@make fclean -C $(PRINTF)

re : fclean all

.PHONY: all printf_lib bonus clean fclean re