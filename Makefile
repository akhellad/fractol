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
			multibrot.c

OBJ		= 	$(addprefix $(OBJDIR)/,$(SRC:.c=.o))

HEADER	=	fractol.h
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -O2 -march=native -g3

MLX_DIR	=	./mlx
MLX_INC	=	-I $(MLX_DIR)
MLX_LIB	=	$(addprefix $(MLX_DIR),mlx.a)

ifeq ($(OS), Linux)
	MLX_LNK	= -L $(MLX_DIR) -l mlx -lXext -lX11 -lpthread -lm
else
	MLX_LNK	= -L $(MLX_DIR) -l mlx -framework OpenGL -framework AppKit
endif

.PHONY: all clean fclean re

all: obj $(MLX_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(MLX_INC) -I $(INCDIR) -o $@ -c $<

$(MLX_LIB):
	make -C $(MLX_DIR)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LNK) -o $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)
	make -C $(MLX_DIR) clean

re: fclean all
