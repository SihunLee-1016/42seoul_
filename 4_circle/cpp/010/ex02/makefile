# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: silee <silee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 17:27:40 by silee             #+#    #+#              #
#    Updated: 2022/12/30 13:01:03 by silee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ref

SRCS = ./main.cpp

OBJS = ${SRCS:.cpp=.o}

CXX		= c++

RM		= rm -f

# -g3 -fsanitize=address
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

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
