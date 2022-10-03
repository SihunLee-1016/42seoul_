NAME		=	miniRT

RED			=	\033[0;31m
GRN			= 	\033[0;32m
YLW			=	\033[0;33m
BLU			= 	\033[0;36m
DFT			= 	\033[0;37m

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
AR			=	ar rcs
RM			=	rm -f

GNL_DIR		=	./gnl/
GNL_NAME	=	gnl.a
GNLS		=	$(addprefix $(GNL_DIR), $(GNL_NAME))
MLX_DIR		=	./mlx/

MLX_FLAGS	=	-L./mlx -lmlx -framework OpenGL -framework Appkit

SRC			=	src/minirt.c \
				\
				src/parse/parse.c \
				src/parse/parse_obj.c \
				src/parse/parse_scene.c \
				src/parse/parse_get.c \
				src/parse/parse_check.c \
				src/parse/parse_utils.c \
				\
				src/hook/key.c \
				src/hook/key_obj.c \
				src/hook/key_scene.c \
				src/hook/transform.c \
				\
				src/draw/draw.c \
				src/draw/draw_utils.c \
				src/draw/hit.c \
				src/draw/hit_cylinder.c \
				src/draw/phong.c \
				\
				src/utils/init.c \
				src/utils/main_utils.c \
				src/utils/str_utils.c \
				src/utils/list_utils.c \
				src/utils/vec_utils_1.c \
				src/utils/vec_utils_2.c \
				src/utils/vec_utils_3.c \
				src/utils/vec_utils_4.c \
				
OBJ			=	$(SRC:.c=.o)

INC			=	-I./include

all : $(NAME) 

%.o : %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJ)
	@$(MAKE) -C $(GNL_DIR)
	@$(MAKE) -C $(MLX_DIR)
	@$(CC) -o $(NAME) $(OBJ) $(GNLS) $(MLX_FLAGS)
	@echo "$(NAME) is $(GRN)ready$(DFT)"

clean :
	@$(MAKE) -C $(GNL_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	@$(RM) $(OBJ)
	@echo "$(RED)cleaned$(DFT)"

fclean : clean
	@$(MAKE) -C $(GNL_DIR) fclean
	@$(RM) $(NAME)
	@echo "$(RED)fcleaned$(DFT)"

re : fclean all

PHONY	: all clean fclean re