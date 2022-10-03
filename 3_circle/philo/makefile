# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 15:47:27 by silee             #+#    #+#              #
#    Updated: 2022/07/15 15:47:28 by silee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosopher

SRCS = ft_atoi.c ft_check_time.c ft_init.c ft_itoa.c ft_philo.c ft_util.c \
		ft_util2.c main.c

OBJS = ${SRCS:.c=.o}

HEADER = philo.h

CC		= cc

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
