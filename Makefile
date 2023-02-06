NAME	=	fractol
OS		=	${shell uname}


SRCDIR	=	./src
INCDIR	=	./includes
OBJDIR	=	./obj

SRC		=	main.c \
			utils.c \
			fractal_set.c \
			mandelbrot.c \
			param.c \
			window.c \
			image.c \
			thread.c \
			color.c \
			julia.c \
			hook.c \
			burning_ship.c \
			palettes.c \
			interface.c \
			ft_itoa.c \
			multibrot.c \


OBJ		= 	$(addprefix $(OBJDIR)/,$(SRC:.c=.o))

HEADER	=	fractol.h
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -o2 -march=native -g3

MLX_INC	=	-I $(MLX)
MLX_LIB	=	$(addprefix $(MLX),mlx.a)
MLX		=	./mlx1

ifeq ($(OS), Linux)
	MLX_LNK	= -L $(MLX) -l mlx -lXext -lX11 -lpthread
else
	MLX_LNK	= -L $(MLX) -l mlx -framework OpenGL -framework AppKit
endif


all: obj ${NAME}

obj: 
	mkdir ${OBJDIR}

${OBJDIR}/%.o:${SRCDIR}/%.c
	$(CC) ${CFLAGS} ${MLX_INC} -I ${INCDIR} -o $@ -c $<

$(MLX_LIB):
	make -C $(MLX)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(OBJ) ${MLX_LNK} -lm -o $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
