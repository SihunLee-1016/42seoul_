NAME = so_long
SRCS = so_long.c \
	ft_join_without_nl.c ft_strdup_without_nl.c \
	get_next_line.c get_next_line_utils.c \
	map_check.c map_draw.c key.c utils.c

OBJS = ${SRCS:.c=.o}

HEADER = so_long.h

CC		= gcc

RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

all:	${NAME} 


$(NAME): ${OBJS}
		$(CC) $(CFLAGS) -o ${NAME} ${OBJS} -L./mlx/ -lmlx -framework OpenGL -framework AppKit

%.o: %.c
		${CC} ${CFLAGS} -c $< -o $@



clean:
		${RM} ${OBJS} ${OBJSBONUS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re bonus