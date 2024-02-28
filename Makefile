# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awissade <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 15:03:56 by awissade          #+#    #+#              #
#    Updated: 2024/02/03 13:49:48 by awissade         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		client server

NAME_BONUS	=		client_bonus server_bonus

CC			=		cc

CFLAGS		=		-Wextra -Wall -Werror

CLIENT_SRC	=		client.c ft_atoi.c ft_putnbr.c

SERVER_SRC	=		server.c ft_putnbr.c ft_atoi.c

CLIENT_OBJ	=		$(CLIENT_SRC:%.c=%.o)

SERVER_OBJ	=		$(SERVER_SRC:%.c=%.o)

CLIENT_SRC_BONUS	=		client_bonus.c ft_atoi.c ft_itoa.c

SERVER_SRC_BONUS	=		server_bonus.c ft_putnbr.c ft_atoi.c

CLIENT_OBJ_BONUS	=		$(CLIENT_SRC_BONUS:%.c=%.o)

SERVER_OBJ_BONUS	=		$(SERVER_SRC_BONUS:%.c=%.o)



all			:		$(NAME)

bonus		:		$(NAME_BONUS)

$(NAME)		:		$(CLIENT_OBJ) $(SERVER_OBJ)
			$(CC) $(CFLAGS) $(CLIENT_OBJ) -o client
			$(CC) $(CFLAGS) $(SERVER_OBJ) -o server

$(NAME_BONUS)	:	$(CLIENT_OBJ_BONUS) $(SERVER_OBJ_BONUS)
			$(CC) $(CFLAGS) $(CLIENT_OBJ_BONUS) -o client_bonus
			$(CC) $(CFLAGS) $(SERVER_OBJ_BONUS) -o server_bonus

%.o			:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean		:
			rm -rf $(CLIENT_OBJ) $(SERVER_OBJ) $(CLIENT_OBJ_BONUS) $(SERVER_OBJ_BONUS)


fclean		:		clean
			rm -rf $(NAME) $(NAME_BONUS)

re			: fclean all

re_bonus	: fclean bonus


.PHONY		: all clean fclean re bonus re_bonus
