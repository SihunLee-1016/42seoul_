# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/01 17:34:37 by silee             #+#    #+#              #
#    Updated: 2022/05/04 14:37:35 by silee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = path.c ft_split.c pipex.c util.c

OBJS = ${SRCS:.c=.o}

HEADER = pipex.h

CC		= gcc

RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

all:	${NAME}

$(NAME): ${OBJS}
		$(CC) $(CFLAGS) -o ${NAME} ${OBJS}

#%.ㅁ : .ㅁ로 끝나는 모든 파일을 말함
%.o: %.c
		${CC} ${CFLAGS} -c $< -o $@



clean:
		${RM} ${OBJS} ${OBJSBONUS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re bonus
