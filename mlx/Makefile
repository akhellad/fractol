SRCS = fractol.c
OBJS = ${SRCS:.c=.o}
BONUS_OBJS	= $(BONUS:.c=.o)
NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
ARRC = ar rc
HEADER = mlx.h

all: ${NAME} ${MLX_INC}

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@


$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
clean:
	${RM} ${OBJS} $(BONUS_OBJS) 

fclean:	clean
	${RM} ${NAME}

re: fclean all
