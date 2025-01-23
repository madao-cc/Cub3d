# Standard
NAME	=	cubito

# Directories
MLX_PATH	=	./minilibx-linux
MINILIBX	=	-I /usr/include -I $(MLX_PATH)

# Compiler and Flags
CC		=	cc
CFLAGS		=	-Wall -Wextra -Werror -O3 -ffast-math
MLX_FLAGS	=	-L $(MLX_PATH) -lmlx -L /usr/lib -lXext -lX11 -lm

# Source files
SRC	=	cub.c	\
		game.c	\
		rendering.c	\
		move.c	\

# Object files
OBJ	=	$(SRC:.c=.o)

# Rules

start:
	@echo "Compiling cub3d..."
	@make all

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(MINILIBX) $(OBJ) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
