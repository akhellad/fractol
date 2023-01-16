NAME	=	fractol
OS		=	${shell uname}


SRCDIR	=	./src
INCDIR	=	./includes
OBJDIR	=	./obj

SRC		=	fractol.c \
			utils.c \
			hooks.c \
			mendel.c \
			julia.c \
			burning_ship.c

OBJ		= 	$(addprefix $(OBJDIR)/,$(SRC:.c=.o))

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -o2 -march=native -g

MLX_INC	=	-I $(MLX)
MLX_LIB	=	$(addprefix $(MLX),mlx.a)
MLX		=	./mlx

ifeq ($(OS), Linux)
	MLX_LNK	= -L $(MLX) -l mlx -lXext -lX11  
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

$(NAME): $(OBJ)
	$(CC) $(OBJ) ${MLX_LNK} -lm -o $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
