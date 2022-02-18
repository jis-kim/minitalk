# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 20:52:51 by jiskim            #+#    #+#              #
#    Updated: 2022/02/18 21:45:52 by jiskim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

BONDIR	=	./bonus/
SRCSDIR	=	./srcs/
INCDIR	=	./includes/

SRCS	=	$(SRC_C) $(SRC_S)
OBJS	=	$(SRCS:.c=.o)

SRCS_C	=	$(addprefix $(SRCSDIR), client.c)
SRCS_S	=	$(addprefix $(SRCSDIR), server.c)

OBJS_C	=	$(SRCS_C:.c=.o)
OBJS_S	=	$(SRCS_S:.c=.o)

SRCS_B	=	$(addprefix $(CKDIR), checker.c) $(addprefix $(PSDIR), cmd_ops.c \
			parse.c print.c push_swap_ops.c rotate_ops.c)
OBJS_B	=	$(SRCS_B:.c=.o)

NAME	=	minitalk
CLIENT	=	client
SERVER	=	server

D_TEST	=	a.out
DFLAG	=	-g3

COMPILE_MSG = @echo $(BOLD)$(L_PUPLE) 🔥 $(SERVER) and 🌾 $(CLIENT) Compiled 🍚$(RESET)

all	: $(NAME)

%.o	: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(NAME) : $(CLIENT) $(SERVER)

$(CLIENT) : $(OBJS_C)
	@$(CC) $(CFLAGS) $(OBJS_C) -o $@

$(SERVER) : $(OBJS_S)
	@$(CC) $(CFLAGS) $(OBJS_S) -o $@
	$(COMPILE_MSG)

bonus : $(BONUS)

$(BONUS) :  $(OBJS_B)
	$(CC) $(CFLAGS) $(OBJS_B) -o $@

debug : $(D_TEST)

advd : fclean
	$(CC) $(DFLAG) -fsanitize=address $(SRCS)

$(D_TEST) : fclean
	$(CC) $(CFLAGS) $(DFLAG) $(SRCS)

clean :
	rm -f $(OBJS) $(OBJS_B)

dclean :
	rm -rf $(D_TEST) a.out.dSYM

fclean : clean dclean
	rm -f $(SERVER) $(CLIENT) $(BONUS)

re : fclean all

.PHONY: all clean fclean re debug advd dclean bonus

######################### Color #########################
GREEN="\033[32m"
L_GREEN="\033[1;32m"
RED="\033[31m"
L_RED="\033[1;31m"
RESET="\033[0m"
BOLD="\033[1m"
L_PUPLE="\033[1;35m"
L_CYAN="\033[1;96m"
UP = "\033[A"
CUT = "\033[K"
