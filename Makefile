############### VARIABLES ###############
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = test.c
OBJ = $(SRC:.c=.o)

COL_GREEN = \e[1;32m
COL_GREY = \e[1;30m
COL_BLUE = \e[1;34m
COL_END = \e[0m

############### LIBRARIES ###############
LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/libftprintf.a

################# RULES #################
all: make_libft make_ft_printf make_get_next_line $(NAME)

make_libft:
	@echo "$(COL_BLUE)Building libft.a$(COL_END)"
	cd libft && make > /dev/null

make_ft_printf:
	@echo "$(COL_BLUE)Building libftprintf.a$(COL_END)"
	cd ft_printf && make > /dev/null

make_get_next_line:
	@echo "$(COL_BLUE)Building get_next_line objects$(COL_END)"
	cd get_next_line && $(CC) $(CFLAGS) -c get_next_line.c -o get_next_line.o > /dev/null && $(CC) $(CFLAGS) -c get_next_line_utils.c -o get_next_line_utils.o

$(NAME): $(OBJ)
	@echo "$(COL_BLUE)Building $(NAME)$(COL_END)"
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo "$(COL_GREEN)so_long ready !$(COL_END)"

$(OBJ) : $(SRC)
	@echo "$(COL_BLUE)Creating .o files$(COL_END)"
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

fclean: clean
	@echo "$(COL_GREY)Removing $(NAME)$(COL_END)"
	$(RM) $(NAME)
	@echo "$(COL_GREY)Removing libft$(COL_END)"
	cd libft && make fclean > /dev/null
	@echo "$(COL_GREY)Removing ft_printf$(COL_END)"
	cd ft_printf && make fclean > /dev/null
	@echo "$(COL_GREY)Removing get_next_line$(COL_END)"
	cd get_next_line && $(RM) *.o

clean:
	@echo "$(COL_GREY)Removing .o files$(COL_END)"
	$(RM) $(OBJ)

re: fclean all