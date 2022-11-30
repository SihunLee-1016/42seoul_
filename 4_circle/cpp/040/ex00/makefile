# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: silee <silee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 17:27:40 by silee             #+#    #+#              #
#    Updated: 2022/11/30 15:16:01 by silee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex00

SRCS = ./main.cpp ./Dog.cpp ./Cat.cpp ./Animal.cpp ./Wronganimal.cpp ./Wrongcat.cpp

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
