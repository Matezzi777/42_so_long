CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long

SRC = test.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(OBJ) : $(SRC)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJ)

re: fclean all