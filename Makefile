NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = so_long.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $< -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $@

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux/minilibx-linux -O3 -c $< -o $@

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJ)

re: fclean all
