############### VARIABLES ###############
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LINKER = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
SRC = so_long.c check_map.c check_map_utils.c
OBJ = $(SRC:.c=.o)

############### LIBRARIES ###############
LIBFT = ./lib_libft/libft.a
PRINTF = ./lib_printf/libftprintf.a

################ COLORS #################
COL_GREEN = \e[1;32m
COL_GREY = \e[1;30m
COL_BLUE = \e[1;34m
COL_END = \e[0m

################# RULES #################
all: make_libft make_ft_printf make_mlx $(NAME)

make_libft:
	cd ./lib_libft && make > /dev/null

make_ft_printf:
	cd ./lib_printf && make > /dev/null

make_get_next_line:
	cd get_next_line && $(CC) $(CFLAGS) -c get_next_line.c -o get_next_line.o > /dev/null && $(CC) $(CFLAGS) -c get_next_line_utils.c -o get_next_line_utils.o

make_mlx:
	cd mlx_linux && make > /dev/null

$(NAME): $(OBJ)
	$(CC) -L$(LIBFT_PATH) -l:$(LIBFT) -L$(PRINTF_PATH) -l:$(FT_PRINTF) -I. -I$(LIBFT_PATH) -I$(PRINTF_PATH) -I$(GNL_PATH) $(LINKER) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

fclean: clean
	$(RM) $(NAME)
	cd lib_libft && make fclean > /dev/null
	cd lib_printf && make fclean > /dev/null
	cd mlx_linux && make clean > /dev/null
	cd get_next_line && $(RM) *.o

clean:
	$(RM) $(OBJ)

re: fclean all