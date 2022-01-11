# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 17:55:10 by silee             #+#    #+#              #
#    Updated: 2022/01/04 13:29:00 by silee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isdigit.c ft_memset.c ft_strjoin.c ft_strtrim.c ft_isprint.c\
ft_putchar_fd.c ft_strlcat.c ft_substr.c ft_atoi.c ft_itoa.c ft_putendl_fd.c\
ft_strlcpy.c ft_tolower.c ft_bzero.c ft_memcpy.c ft_putnbr_fd.c ft_strlen.c\
ft_toupper.c ft_calloc.c ft_memchr.c ft_putstr_fd.c ft_strmapi.c ft_isalnum.c\
ft_memcmp.c ft_split.c ft_strncmp.c ft_isalpha.c ft_memcpy.c ft_strchr.c\
ft_strnstr.c ft_isascii.c ft_memmove.c ft_strdup.c ft_strrchr.c ft_striteri.c

BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c\
		ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJS = ${SRCS:.c=.o}
#${~~~~ :.c=.o}.c로 되어있는 파일들을 .o로 변환해주는 것.

OBJSBONUS = ${BONUS:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -I libft.h -c $< -o ${<:.c=.o}


#.c.o :
#	$(CC)  $(CFLAGS) 		  -c     $<	 	-o $(<:.c=.o) -I. 가 실제로 적용되면
#	gcc -Werror -Wextra -Wall -c filename.c -o filename.o -I.

# -c 옵션 : 컴파일작업만 하는경우 *.o 확장자인 오브젝트 파일이 생성된다.
# -I 옵션 : 컴파일을 할 때 include 할 header가있는 directory를 설정해주는 옵션.
# <:.c=.o : .c파일을 .o로 변환 시 자동 적용되는 규칙.
$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

# ar : 명령어 옵션 ar은 묶음 파일을 만들고 조작하고 추출한다. rcs는 그에 대한 옶ㄴ들.
# rcs  
#r : 지정한 아카이브로 모듈 추가(.o파일)
#c : 라이브러리 생성
#s : 인덱스 생성

bonus:	${OBJS} ${OBJSBONUS}
		ar rcs ${NAME} ${OBJS} ${OBJSBONUS}

all:	${NAME}

clean:
		${RM} ${OBJS} ${OBJSBONUS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re bonus
# 만약 명령어와 파일의 이름이 동일하다면 충돌이 일어난다.
# 만약 동일한 이름의 파일이 존재한다면, 가짜목적물은 종속물을 갖지 않기때문에 동일한 이름의 파일은 명령어가 아닌 파일명으로 여겨질 것이고
# 정의한 명령어는 결코 수행되지 않을 것이다. 이런 경우 가짜 목적물 (phony target)을 사용해 동일명의 파일을 신경쓰지 않고 명령을
# 실행할 수 있다. 
