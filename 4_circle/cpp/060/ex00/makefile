# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sihunlee <sihunlee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 12:46:24 by silee             #+#    #+#              #
#    Updated: 2022/12/19 15:17:25 by sihunlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex00

SRCS = ./main.cpp

OBJS = ${SRCS:.cpp=.o}

CXX		= clang++

RM		= rm -f

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all:	${NAME}

$(NAME): ${OBJS}
		$(CXX) $(CXXFLAGS) -o ${NAME} ${OBJS}

%.o: %.c
		${CXX} ${CXXFLAGS} -c $< -o $@

clean:
		${RM} ${OBJS} ${OBJSBONUS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re bonus
