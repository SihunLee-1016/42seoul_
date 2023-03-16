NAME = btc

SRCS = ./BitcoinExchange.cpp

OBJS = ${SRCS:.cpp=.o}

CXX		= c++

RM		= rm -f

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address

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
