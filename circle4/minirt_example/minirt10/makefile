# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/01 17:34:37 by silee             #+#    #+#              #
#    Updated: 2022/09/06 15:03:26 by silee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test

SRCS = src/print/print.c src/scene/canvas.c src/trace/ray.c src/utils/vec3_utils.c  \
		src/scene/create.c src/trace/hit_sphere.c src/trace/phong_lighting.c main.c

OBJS = ${SRCS:.c=.o}

# HEADER = pipex.h

CC		= gcc

RM		= rm -f

CFLAGS = 

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