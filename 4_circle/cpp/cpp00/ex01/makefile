# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: silee <silee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 17:27:40 by silee             #+#    #+#              #
#    Updated: 2022/10/21 17:47:29 by silee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

SRCS = ./phone_book.cpp

OBJS = ${SRCS:.cpp=.o}

CC		= clang++

RM		= rm -f

# -g3 -fsanitize=address
CFLAGS = -Wall -Wextra -Werror -std=c++98 

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
