# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/01 17:34:37 by silee             #+#    #+#              #
#    Updated: 2022/05/23 12:47:13 by silee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = commands.c d_list.c ft_atoi.c make_hourglass_n_return.c push_swap.c \
	quick_sort.c r_commands.c utils.c check.c three_or_five.c

OBJS = ${SRCS:.c=.o}

HEADER = push_swap.h

CC		= gcc

RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

all:	${NAME}

$(NAME): ${OBJS}
		$(CC) $(CFLAGS) -o ${NAME} ${OBJS}

%.o: %.c
		${CC} ${CFLAGS} -c $< -o $@



clean:
		${RM} ${OBJS} ${OBJSBONUS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re bonus
