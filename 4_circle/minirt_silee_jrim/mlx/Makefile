#
#

NOM		=	libmlx.a
SRC_C	= 	mlx_shaders.c mlx_xpm.c mlx_int_str_to_wordtab.c mlx_png.c
SRC_M	=	mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_mouse.m
OBJ_C	=	$(SRC_C:.c=.o)
OBJ_M	=	$(SRC_M:.m=.o)

CC		=	cc
CFLAGS	=	-O2 -w -DSTRINGPUTX11
AR		=	ar -r
RANLIB	=	ranlib

RED		=	\033[0;31m
GRN		= 	\033[0;32m
YLW		=	\033[0;33m
BLU		= 	\033[0;36m
DFT		= 	\033[0;37m

all: $(NOM)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

%.o : %.m
	@$(CC) $(CFLAGS) -c $< -o $(<:.m=.o)

$(NOM):	$(OBJ_C) $(OBJ_M)
	@-$(AR) $(NOM) $(OBJ_C) $(OBJ_M)
	@$(RANLIB) $(NOM)
	@echo "libmlx is $(GRN)ready$(DFT)"

clean:
	@rm -f $(NOM) $(OBJ_C) $(OBJ_M) *~
	@rm -f mlx_app

re: clean all